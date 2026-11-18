#pragma once
#include <Windows.h>
#include <string>
#include <dxgi1_6.h>
class IDX
{
public:
	IDX(UINT width, UINT heigt, std::wstring name);
	virtual ~IDX();

	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnDestroy() = 0;
protected:
	void GetHardwareAdapter(_In_ IDXGIFactory1* pFactory, _Outptr_opt_result_maybenull_ IDXGIAdapter1** ppAdapter,bool requestHighPerformanceAdapter = false);
	UINT m_weight;
	UINT m_height;
	std::wstring m_title;
	float aspecrt_ratio;

	bool m_useWarpAdapter;
};