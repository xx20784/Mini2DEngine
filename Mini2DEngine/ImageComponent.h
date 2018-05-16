#pragma once
#include "pch.h"
#include "Component.h"

// Image File로부터 Bitmap 생성 및 Draw를 담당하는 Class.
class Image
{
public:
	// 반드시 Image File을 불러와야 합니다.
	Image() = delete;
	explicit Image(const std::tstring& _path);
	~Image();

public:
	// 생성된 Bitmap을 D2D를 이용하여 Draw.
	void DrawBitmap() const;

private:
	void LoadBitmapFromFile(ID2D1RenderTarget* _rt, IWICImagingFactory* _iWIC, IWICFormatConverter** _format, const std::tstring& _path);

private:
	ID2D1Bitmap* m_bitmap = nullptr;
	IWICFormatConverter* m_converter = nullptr;
};





// 등록된 Image File을 Image Class로 변환 및 Draw 기능을 제공하는 Component.
class ImageComponent : public Component
{
public:
	virtual ~ImageComponent();

public:
	virtual void Update() override;
	virtual void Draw() override;

	// Image File 등록.
	void ChangeImage(const std::tstring& _path);

private:
	Image* m_image = nullptr;
};