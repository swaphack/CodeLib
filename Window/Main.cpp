#include <windows.h>
#include <stdio.h>

#include "resource.h"

#include "WndWeb.h"
#include "WndRender.h"


int WINDOW_SIZE_WIDTH = 1024;
int WINDOW_SIZE_HEIGHT = 768;
const char* WEB_IP = "127.0.0.1";
int WEB_PORT = 9547;


WndRender*		wndRender=NULL;
WndWeb*			wndWeb = NULL;
HGLRC           hRC=NULL;		// ������ɫ��������
HDC             hDC=NULL;		// OpenGL��Ⱦ��������
HWND            hWnd=NULL;		// �������ǵĴ��ھ��
HINSTANCE       hInstance;		// ��������ʵ��


bool            keys[256];				// ������̰���������
bool            active=TRUE;            // ���ڵĻ��־��ȱʡΪTRUE
bool            fullscreen=TRUE;        // ȫ����־ȱʡ��ȱʡ�趨��ȫ��ģʽ
float           rtri;					// ���ڼ�������ת�ĽǶ�

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   // WndProc�Ķ���

// �������ٴ���
void KillGLWindow()      
{
	if (fullscreen)	// ���Ǵ���ȫ��ģʽ��?
	{
		ChangeDisplaySettings(NULL,0);	// �ǵĻ����л������棬��Ϊȫ��ģʽֱ�ӹرմ��ڣ�������������
		ShowCursor(TRUE);				// ��ʾ���ָ��
	}
	if (hRC)	// ����ӵ��OpenGL��Ⱦ��������?
	{
		if (!wglMakeCurrent(NULL,NULL))	// �����ܷ��ͷ�DC��RC������?
		{
			MessageBox(NULL,TEXT("�ͷ�DC��RCʧ�ܡ�"),TEXT("�رմ���"),MB_OK | MB_ICONINFORMATION);
		}
		if (!wglDeleteContext(hRC))	// �����ܷ�ɾ��RC?
		{
			MessageBox(NULL,TEXT("�ͷ�RCʧ�ܡ�"),TEXT("�رմ���"),MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;	// ��RC��Ϊ NULL
	}
	if (hDC && !ReleaseDC(hWnd,hDC))	// �����ܷ��ͷ� DC?
	{
		MessageBox(NULL,TEXT("�ͷ�DCʧ�ܡ�"),TEXT("�رմ���"),MB_OK | MB_ICONINFORMATION);
		hDC=NULL;	// �� DC ��Ϊ NULL
	}
	if (hWnd && !DestroyWindow(hWnd))	// �ܷ����ٴ���?
	{
		MessageBox(NULL,TEXT("�ͷŴ��ھ��ʧ�ܡ�"),TEXT("�رմ���"),MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;	// �� hWnd ��Ϊ NULL
	}
	if (!UnregisterClass(TEXT("OpenGL"),hInstance))	// �ܷ�ע����?
	{
		MessageBox(NULL,TEXT("����ע�������ࡣ"),TEXT("�رմ���"),MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;	// �� hInstance ��Ϊ NULL
	}
}

LPCWCHAR getWCHAR(char* szStr)
{
	WCHAR wszClassName[256];
	memset(wszClassName,0,sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP,0,szStr,strlen(szStr)+1,wszClassName,
		sizeof(wszClassName)/sizeof(wszClassName[0]));

	return wszClassName;
}

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	//����Ҫ��WindowsΪ����Ѱ����ƥ������ظ�ʽʱ��WindowsѰ�ҽ�����ģʽֵ�����ڱ���PixelFormat��
	GLuint PixelFormat;			// �������ƥ��Ľ��
	WNDCLASS sys;				// ������ṹ
	DWORD dwExStyle;			// ��չ���ڷ��
	DWORD dwStyle;				// ���ڷ��
	RECT WindowRect;			// ȡ�þ��ε����ϽǺ����½ǵ�����ֵ

	WindowRect.left=(long)0;			// ��Left   ��Ϊ 0
	WindowRect.right=(long)width;       // ��Right ��ΪҪ��Ŀ��
	WindowRect.top=(long)0;             // ��Top    ��Ϊ 0
	WindowRect.bottom=(long)height;     // ��Bottom ��ΪҪ��ĸ߶�

	fullscreen = fullscreenflag;				// ����ȫ��ȫ����־
	hInstance = GetModuleHandle(NULL);          // ȡ�����Ǵ��ڵ�ʵ��

	sys.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// �ƶ�ʱ�ػ�����Ϊ����ȡ��DC��CS_OWNDCΪ���ڴ���һ��˽�е�DC������ζ��DC�����ڳ���乲��
	sys.lpfnWndProc = (WNDPROC) WndProc;             // WndProc������Ϣ
	sys.cbClsExtra = 0;                              // �޶��ⴰ������
	sys.cbWndExtra = 0;                              // �޶��ⴰ������
	sys.hInstance = hInstance;						// ����ʵ��
	sys.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// װ��ȱʡͼ��
	sys.hCursor  = LoadCursor(NULL, IDC_ARROW);		// װ��Ĭ�����ָ��
	sys.hbrBackground = NULL;                        // GL����Ҫ����
	sys.lpszMenuName  = NULL;                        // ����Ҫ�˵�
	sys.lpszClassName = TEXT("OpenGL");              // �趨������

	if (!RegisterClass(&sys))	// ����ע�ᴰ����
	{
		MessageBox(NULL,TEXT("ע�ᴰ��ʧ��"),TEXT("����"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// �˳�������FALSE
	}
	if (fullscreen)	// Ҫ����ȫ��ģʽ��?
	{
		DEVMODE dmScreenSettings;								// �豸ģʽ
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// ȷ���ڴ����Ϊ��
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);     // Devmode �ṹ�Ĵ�С
		dmScreenSettings.dmPelsWidth = width;                   // ��ѡ��Ļ���
		dmScreenSettings.dmPelsHeight = height;                 // ��ѡ��Ļ�߶�
		dmScreenSettings.dmBitsPerPel = bits;					// ÿ������ѡ��ɫ�����                    
		//dmScreenSettings.dmFields = DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;
		// ����������ʾģʽ�����ؽ����ע: CDS_FULLSCREEN ��ȥ��״̬����
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// ��ģʽʧ�ܣ��ṩ����ѡ��˳����ڴ��������С�
			if (MessageBox(NULL,TEXT("ȫ��ģʽ�ڵ�ǰ�Կ�������ʧ�ܣ�\nʹ�ô���ģʽ��"),TEXT("NeHe G"),MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;// ѡ�񴰿�ģʽ(Fullscreen=FALSE)
			}
			else
			{
				// ����һ���Ի��򣬸����û��������
				MessageBox(NULL,TEXT("���򽫱��ر�"),TEXT("����"),MB_OK|MB_ICONSTOP);
				return FALSE;               // �˳������� FALSE
			}
		}
	}
	if (fullscreen)	// �Դ���ȫ��ģʽ��?
	{
		dwExStyle=WS_EX_APPWINDOW;	// ��չ������
		dwStyle=WS_POPUP;			// ������
		ShowCursor(FALSE);          // �������ָ��
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	// ��չ������
		dwStyle=WS_OVERLAPPEDWINDOW;                    // ������
	}
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle); // �������ڴ�С
	if (!(hWnd=CreateWindowEx(        
		dwExStyle,									// ��չ������
		TEXT("OpenGL"),								// ������
		getWCHAR(title),							// ���ڱ���
		WS_CLIPSIBLINGS |							// ����Ĵ���������
		WS_CLIPCHILDREN |							// ����Ĵ���������
		dwStyle,									// ѡ��Ĵ�������
		0, 0,										// ����λ��
		WindowRect.right-WindowRect.left,			// ���
		WindowRect.bottom-WindowRect.top,			// �߶�
		NULL,                                       // �޸�����
		NULL,                                       // �޲˵�
		hInstance,                                  // ʵ��
		NULL)))										// ����WM_CREATE�����κζ���
	{
		KillGLWindow();	// ������ʾ��
		MessageBox(NULL,TEXT("���ܴ���һ�������豸������"),TEXT("����"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// ���� FALSE
	}
	static PIXELFORMATDESCRIPTOR pfd=	// /pfd ���ߴ�ʹ�õ����ظ�ʽ
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// ������ʽ�������Ĵ�С
		1,											// �汾��
		PFD_DRAW_TO_WINDOW |                        // ��ʽ֧�ִ���
		PFD_SUPPORT_OPENGL |						// ��ʽ����֧��OpenGL
		PFD_DOUBLEBUFFER,							// ����֧��˫����
		PFD_TYPE_RGBA,								// ���� RGBA ��ʽ
		bits,                                       // ѡ��ɫ�����
		0, 0, 0, 0, 0, 0,                           // ���Ե�ɫ��λ
		0,                                          // ��Alpha����
		0,                                          // ����Shift Bit
		0,                                          // ���ۼӻ���
		0, 0, 0, 0,                                 // ���Ծۼ�λ
		16,                                         // 16λ Z-���� (��Ȼ���)
		0,                                          // ���ɰ建��
		0,                                          // �޸�������
		PFD_MAIN_PLANE,								// ����ͼ��
		0,                                          // Reserved
		0, 0, 0                                     // ���Բ�����
	};
	if (!(hDC=GetDC(hWnd)))	// ȡ���豸��������ô?
	{
		KillGLWindow();	// ������ʾ��
		MessageBox(NULL,TEXT("���ܴ���һ����ƥ������ظ�ʽ"),TEXT("����"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// ���� FALSE
	}
	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Windows �ҵ���Ӧ�����ظ�ʽ����?
	{
		KillGLWindow();	// ������ʾ��
		MessageBox(NULL,TEXT("�����������ظ�ʽ"),TEXT("����"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// ���� FALSE
	}
	if(!SetPixelFormat(hDC,PixelFormat,&pfd))	// �ܹ��������ظ�ʽô?
	{
		KillGLWindow();	// ������ʾ��
		MessageBox(NULL,TEXT("�����������ظ�ʽ"),TEXT("����"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// ���� FALSE
	}
	if (!(hRC=wglCreateContext(hDC)))	// �ܷ�ȡ����ɫ������?
	{
		KillGLWindow();	// ������ʾ��
		MessageBox(NULL,TEXT("���ܴ���OpenGL��Ⱦ������"),TEXT("����"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// ���� FALSE
	}
	if(!wglMakeCurrent(hDC,hRC))	// ���Լ�����ɫ������
	{
		KillGLWindow();	// ������ʾ��
		MessageBox(NULL,TEXT("���ܼ��ǰ��OpenGL��Ȼ������"),TEXT("����"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// ���� FALSE
	}
	ShowWindow(hWnd,SW_SHOW);	// ��ʾ����
	SetForegroundWindow(hWnd);	// ����������ȼ�
	SetFocus(hWnd);	// ���ü��̵Ľ������˴���

	return TRUE;	// �ɹ�
}



LRESULT CALLBACK WndProc( 
	HWND hWnd,                          // ���ڵľ��
	UINT uMsg,                          // ���ڵ���Ϣ
	WPARAM wParam,                      // ���ӵ���Ϣ����
	LPARAM lParam)						// ���ӵ���Ϣ����
{
	switch (uMsg)	// ���Windows��Ϣ
	{
	case WM_ACTIVATE:	// ���Ӵ��ڼ�����Ϣ
		{
			if (!HIWORD(wParam))	// �����С��״̬
			{
				active=TRUE;	// �����ڼ���״̬
			}
			else
			{
				active=FALSE;	// �����ټ���
			}

			return 0;			// ������Ϣѭ��
		}
	case WM_SYSCOMMAND:				// ϵͳ�ж�����
		{
			switch (wParam)		// ���ϵͳ����
			{
			case SC_SCREENSAVE:		// ����Ҫ����?
			case SC_MONITORPOWER:	// ��ʾ��Ҫ����ڵ�ģʽ?
				return 0;      // ��ֹ����
			}
			break;	// �˳�
		}
	case WM_CLOSE:	// �յ�Close��Ϣ?
		{
			PostQuitMessage(0);	// �����˳���Ϣ
			return 0;	// ����
		}
	case WM_KEYDOWN:	// �м�����ô?
		{
			keys[wParam] = TRUE;	// ����ǣ���ΪTRUE
			return 0;	// ����
		}
	case WM_KEYUP:	// �м��ſ�ô?
		{
			keys[wParam] = FALSE;	// ����ǣ���ΪFALSE
			return 0;	// ����
		}
	case WM_SIZE:		// ����OpenGL���ڴ�С
		{
			wndRender->setFrameSize(LOWORD(lParam),HIWORD(lParam));                      // LoWord=Width,HiWord=Height
			return 0;	// ����
		}
// 	case WM_MOUSEMOVE:
// 	{
// 
// 	}
// 	case WM_LBUTTONDOWN:
// 	case WM_LBUTTONUP:
	}
	// �� DefWindowProc��������δ�����Ĭ����Ϣ��
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}



int  WINAPI WinMain(HINSTANCE	hInstance,                 // ��ǰ����ʵ��
					HINSTANCE	hPrevInstance,             // ǰһ������ʵ��
					LPSTR		lpCmdLine,                 // �����в���
					int			nCmdShow)                  // ������ʾ״̬
{

	//����̨���
	AllocConsole();
	//AttachConsole(ATTACH_PARENT_PROCESS); // ����ǰ�����ŵ���������  
	freopen("CONIN$", "r+t", stdin); // �ض��� STDIN  
	freopen("CONOUT$", "w+t", stdout); // �ض���STDOUT  

	MSG msg;			// Windowsx��Ϣ�ṹ
	BOOL done=FALSE;	// �����˳�ѭ����Bool ����
	// ��ʾ�û�ѡ������ģʽ
// 	if (MessageBox(NULL,TEXT("������ȫ��ģʽ������ô��"), TEXT("����ȫ��ģʽ"),MB_YESNO|MB_ICONQUESTION)==IDNO)
// 	{
// 		fullscreen=FALSE; // FALSEΪ����ģʽ
// 	}

	fullscreen = FALSE; // FALSEΪ����ģʽ
	// ����OpenGL����
	/*CreateGLWindow�����Ĳ�������Ϊ���⡢��ȡ��߶ȡ�ɫ����ȣ��Լ�ȫ����־������ô�򵥣��Һ�������δ���ļ�ࡣ���δ�ܴ����ɹ�����������FALSE�����������˳���*/
	if (!CreateGLWindow("win32 ",WINDOW_SIZE_WIDTH,WINDOW_SIZE_HEIGHT,16,fullscreen))
	{
		return 0;	// ʧ���˳�
	}

	wndRender = new WndRender();
	wndRender->setFrameSize(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	wndRender->test();
	
	//wndWeb = new WndWeb(WEB_IP, WEB_PORT);

	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT)
			{
				done=TRUE;
			}
			else
			{
				TranslateMessage(&msg);                                  // ������Ϣ
				DispatchMessage(&msg);                                   // ������Ϣ
			}
		}
		else // ���û����Ϣ
		{
			if (active)
			{
				if (keys[VK_ESCAPE])
				{
					done=TRUE;
				}
				else
				{
					wndRender->update();		// ���Ƴ���
					SwapBuffers(hDC);			// �������� (˫����)
					
				}
			}
			//wndWeb->update();
		}
	}
	// �رճ���
	KillGLWindow();                                                                                                                                                          // ���ٴ���
	return (msg.wParam);                                                                                                                           // �˳�����
}
