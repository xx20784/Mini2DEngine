#pragma once
#include "pch.h"
#include "Component.h"

// Image File�κ��� Bitmap ���� �� Draw�� ����ϴ� Class.
class Image
{
public:
	// �ݵ�� Image File�� �ҷ��;� �մϴ�.
	Image() = delete;
	explicit Image(const std::tstring& _path);
	~Image();

public:
	// ������ Bitmap�� D2D�� �̿��Ͽ� Draw.
	void DrawBitmap() const;

private:
	void LoadBitmapFromFile(ID2D1RenderTarget* _rt, IWICImagingFactory* _iWIC, IWICFormatConverter** _format, const std::tstring& _path);

private:
	ID2D1Bitmap* m_bitmap = nullptr;
	IWICFormatConverter* m_converter = nullptr;
};





// ��ϵ� Image File�� Image Class�� ��ȯ �� Draw ����� �����ϴ� Component.
class ImageComponent : public Component
{
public:
	virtual ~ImageComponent();

public:
	virtual void Update() override;
	virtual void Draw() override;

	// Image File ���.
	void ChangeImage(const std::tstring& _path);

private:
	Image* m_image = nullptr;
};