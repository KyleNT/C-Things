#include <windows.h>
/* inclui o arquivo de cabe�alho windows.h, que cont�m declara��es 
para todas as fun��es da API do Windows, tipos de dados e constantes 
necess�rias para criar aplica��es Windows.*/

// Prot�tipo da fun��o de tratamento de mensagens da janela
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
/*Declara um prot�tipo para a fun��o de procedimento da janela. 
Esta fun��o � chamada pela API do Windows para tratar mensagens direcionadas para a janela, 
como cliques do mouse, movimentos, fechamento da janela, etc.*/


char szClassName[] = "WindowsApp";

/*WinMain � o ponto de entrada para uma aplica��o Windows, 
equivalente � fun��o main em programas C padr�o. 
Esta fun��o � chamada pelo sistema operacional quando a aplica��o � iniciada.*/
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl; /*Define uma estrutura que cont�m informa��es sobre a classe da janela. Esta estrutura � usada para registrar a classe da janela e definir algumas propriedades importantes, como o estilo da janela, o �cone, o cursor e a fun��o de procedimento da janela.*/

    // Estrutura de defini��o da janela
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof(WNDCLASSEX);
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

	/*Registra a classe da janela com a API do Windows. 
	Se o registro falhar, o programa termina imediatamente.*/
    if (!RegisterClassEx(&wincl))
        return 0;

    // Cria��o da janela
    /*Cria uma janela usando a classe registrada. 
	Define o estilo da janela, o t�tulo, as dimens�es e outros par�metros importantes.*/
    hwnd = CreateWindowEx(
        0,
        szClassName,
        "Clique do Mouse Detector",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        544,
        375,
        HWND_DESKTOP,
        NULL,
        hThisInstance,
        NULL
    );
	
	/*ShowWindow exibe a janela na tela em um estado especificado (nCmdShow). 
	UpdateWindow for�a a janela a se redesenhar.*/
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Loop de mensagens
    /*O loop de mensagens � fundamental em aplica��es Windows. 
	Ele aguarda por mensagens do sistema, como eventos de entrada do usu�rio, 
	e despacha essas mensagens para a fun��o de procedimento da janela apropriada.*/
    while (GetMessage(&messages, NULL, 0, 0)) {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

// Fun��o de tratamento de mensagens
/*Trata as mensagens enviadas para a janela. WM_LBUTTONDOWN e WM_RBUTTONDOWN 
s�o tratados para detectar cliques nos bot�es esquerdo e direito do mouse, respectivamente. 
WM_DESTROY � usado para terminar o loop de mensagens e fechar a aplica��o.*/
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_LBUTTONDOWN:
            MessageBox(hwnd, "Clique esquerdo detectado!", "Evento do Mouse", MB_OK | MB_ICONINFORMATION);
            break;
        case WM_RBUTTONDOWN:
            MessageBox(hwnd, "Clique direito detectado!", "Evento do Mouse", MB_OK | MB_ICONINFORMATION);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
