#include "pch.h"
#include "ImageComponent.h"

#include "GraphicsSystem.h"

using namespace std;

Image::Image(const tstring& _path)
{
	ID2D1RenderTarget* renderTarget = GraphicsSystem::Instance()->GetRT();
	IWICImagingFactory* iWICFactory = GraphicsSystem::Instance()->GetiFactory();

	LoadBitmapFromFile(renderTarget, iWICFactory, &m_converter, _path);
	renderTarget->CreateBitmapFromWicBitmap(m_converter, &m_bitmap);
}

Image::~Image()
{
	m_bitmap->Release();
	m_converter->Release();
}



void Image::DrawBitmap() const
{
	D2D1_RECT_F srcRect;
	srcRect.left = 0.0f;
	srcRect.top = 0.0f;
	srcRect.right = (FLOAT)m_bitmap->GetPixelSize().width;
	srcRect.bottom = (FLOAT)m_bitmap->GetPixelSize().height;

	D2D1_RECT_F dstRect;
	dstRect.left = 0.0f;
	dstRect.top = 0.0f;
	dstRect.right = dstRect.left + (srcRect.right - srcRect.left);
	dstRect.bottom = dstRect.top + (srcRect.bottom - srcRect.top);

	ID2D1RenderTarget* renderTarget = GraphicsSystem::Instance()->GetRT();
	renderTarget->DrawBitmap(m_bitmap, dstRect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
}



void Image::LoadBitmapFromFile(ID2D1RenderTarget* _rt, IWICImagingFactory* _iWIC, IWICFormatConverter** _format, const tstring& _path)
{
	IWICBitmapDecoder* decoder = nullptr;
	IWICBitmapFrameDecode* source = nullptr;

	std::tstring tUri(_path.c_str());
	std::wstring wUri(tUri.begin(), tUri.end());
	if (FAILED(_iWIC->CreateDecoderFromFilename(wUri.c_str(), NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &decoder))) {
		return;
	}

	if (FAILED(decoder->GetFrame(0, &source))) {
		if (decoder != nullptr) {
			decoder->Release();
		}
		return;
	}

	if (FAILED(_iWIC->CreateFormatConverter(_format))) {
		if (decoder != nullptr) {
			decoder->Release();
		}
		if (source != nullptr) {
			source->Release();
		}
		return;
	}

	(*_format)->Initialize(source, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0f, WICBitmapPaletteTypeMedianCut);

	if (decoder != nullptr) {
		decoder->Release();
	}
	if (source != nullptr) {
		source->Release();
	}
}





ImageComponent::~ImageComponent()
{
	delete m_image;
}



void ImageComponent::Update()
{}

void ImageComponent::Draw()
{
	m_image->DrawBitmap();
}



void ImageComponent::ChangeImage(const std::tstring& _path)
{
	if (m_image != nullptr) {
		delete m_image;
	}
	m_image = new Image(_path);
}