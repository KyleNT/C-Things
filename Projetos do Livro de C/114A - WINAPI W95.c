#include <windows.h>
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "MinhaJan"; //Nome da classe da Janela

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode) {
	HWND hwnd;
	MSG msg;
	WNDCLASS wcl;
	
	//Define uma classe de janela
	wcl.hInstance = hThisInst; //Handle desta inst�ncia
	wcl.lpszClassName = szWinName; //Nome da classe de Janela
	wcl.lpfnWndProc = WindowFunc; //Fun��o de janela
	wcl.style = 0; //Estilo Padr�o
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Estilo de �cone
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); //Estilo de cursor
	wcl.lpszMenuName = NULL; //Sem Menu
	wcl.cbClsExtra = 0; //Nenhuma informa��o
	wcl.cbWndExtra = 0; // Extra � necess�ria
	
	//Faz o fundo da janela ser branco
	wcl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	
	//Registra a classe de janela
	if (!RegisterClass(&wcl)) return 0;
	
	//Agora que uma classe de janela foi registrada, pode ser criada uma janela.
	hwnd = CreateWindow(
	szWinName, //Nome da classe da janela
	"Carter '76", //T�tulo
	WS_OVERLAPPEDWINDOW, //Estilo da Janela - Normal
	CW_USEDEFAULT, // Coordenada X Deixe Windows decidir
	CW_USEDEFAULT, // Coordenada Y Deixe Windows decidir
	CW_USEDEFAULT, // Largula Deixe o Windows decidir
	CW_USEDEFAULT, // Altura Deixe Windows decidir
	HWND_DESKTOP, //Nenhuma janela-pai
	NULL, //Sem Menu
	hThisInst, //Handle desta inst�ncia do programa
	NULL //Nenhum argumento adicional
	);
	
	//Exibe a janela
	ShowWindow(hwnd, nWinMode);
	UpdateWindow(hwnd);
	
	//Cria  a repeti��o de mensagens
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); //Permite uso do teclado
		DispatchMessage(&msg); //Retorna o controle ao Windows
	}
	return msg.wParam;
}

//Esta fun��o � chamada pelo Windows 95 e recebe mensagens da fila de mensagens
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message) {
		case WM_DESTROY: //Encerra o programa
			PostQuitMessage(0);
			break;
		default:
			//Deixe o Windows 95 processar quaisquer mensagens n�o especificadas no comando switch acima
			return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
