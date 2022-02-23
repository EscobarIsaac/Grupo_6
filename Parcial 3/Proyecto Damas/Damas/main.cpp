#include "main.h"
#include "EasyBMP.h"
using namespace nlohmann;
using std::vector;
void cargarJuego() {

    system("cls");
    system("pause");
    //Guardo en las variables el directorio de los archivos
    string dir = "C:\\DamasChinas\\partidas";
    string dir2 = "C:\\DamasChinas\\";
    cout << "\n\n";

    //Carga las partidas de la carpeta partidas
    vector <string> files;
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    dir += "\\*";

    hFind = FindFirstFile(dir.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        std::cout << "No existe";
    else
    {
        files.push_back(findFileData.cFileName);
        while (FindNextFile(hFind, &findFileData) != 0)
            files.push_back(findFileData.cFileName);
    }
    std::reverse(files.begin(), files.end());
    files.pop_back();
    files.pop_back();

    int a = 1;

    for (auto f : files) {
        std::cout << a << ".\t\t" << f << std::endl;
        a++;
    }

    cout << "\t Escoje la partida ";
    cin >> a;
    
    string filename = files[a - 1];
    filename.resize(filename.size() - 5);
    //Cargo el archivo seleccionado en el menu de backups
        //Ifstream sirve para leer archivos
    std::ifstream i2("C:\\DamasChinas\\" +filename+".json");
    json j2;
    i2 >> j2;

    //Creo un objeto de tipo DamasChinas
    DamasChinas partida;


    int ki = 10;
    int kj = 10;

    //Alojo memoria char**
    partida.Mmapa = new char* [MAXFILAS];
    for (partida.i = 0; partida.i < MAXFILAS; partida.i++) {
        partida.Mmapa[partida.i] = new char[MAXCOL];
    }
    //Guardo en la variable char** el mapa del json
    for (size_t i = 0; i < MAXFILAS; i++, ki++)
    {
        for (size_t j = 0; j < MAXCOL; j++, kj++)
        {
            partida.Mmapa[i][j] = j2[std::to_string(ki)][std::to_string(kj)].get<int>();
        }
        kj = 10;
    }

    //Cargo los demas datos del juego
    std::ifstream i("C:\\DamasChinas\\partidas\\" + filename + ".json");
    json j;
    i >> j;
    
    partida.coordx=j["coordx"].get<int>();
    partida.coordy=j["coordy"].get<int>();
    partida.destx=j["destx"].get<int>();
    partida.desty=j["desty"].get<int>();
    partida.direccion=j["direccion"].get<int>();
    partida.j1ficha= j["j1ficha"].get<int>();
    partida.j2ficha= j["j2ficha"].get<int>();
    partida.jugador1= j["jugador1"].get<string>();
    partida.jugador2= j["jugador2"].get<string>();
    partida.primerJugador= j["primerJugador"].get<bool>();
    partida.turno= j["turno"].get<int>();
   i2.close();

   //dibujo el mapa cargado
   partida.dibujar_mapa(partida.Mmapa);
   //Inicio la partida cargada
    partida.cargarPartida(partida.Mmapa,partida.turno,partida.coordx,partida.coordy,partida.j1ficha,partida.direccion,partida.destx,partida.desty,partida.j2ficha,partida.primerJugador,partida.jugador1,partida.jugador2);

    system("pause");
}


void opcionJuego()
{
    std::vector<VectorMenu> menu_item
    {
        {1, "Nueva Partida", DamasChinas::jugar},
        {2, "Recargar Partida", cargarJuego},
        {3, "SALIR", exit_program}
    };

    Control menu{ menu_item };
    menu.controlMenu();
}

void principalMenu()
{
	std::vector<VectorMenu> opciones{{1, "Jugar", jugar},{2, "SALIR", exit_program}};
	Control objetoMenu{ opciones };
	objetoMenu.controlMenu();

}

void pedirDatos()
{
    std::vector<VectorMenu> menu_item
    {
        {1, "Login", logearse},
        {2, "Register", registrarse},
        {3, "SALIR", exit_program}
    };

    Control menu{ menu_item };
    menu.controlMenu();
}

void logearse()
{
    system("pause");
    system("cls");
    UserCredenciales log;
    if (log.login() == 1) {
        principalMenu();
    }
    else {
        cout << "\nUsuario Incorrecto" << endl;
        Sleep(600);
    }
    pedirDatos();
}

void registrarse()
{
    system("pause");
    system("cls");
    UserCredenciales log;
    if (log.registrarse() == 1) {
    }
    else {
        cout << "Usuario Incorrecto" << endl;
        Sleep(600);
    }
    pedirDatos();
}

void exit_program()
{
	exit(0);
}

void jugar() {
    system("cls");
    system("pause");
    opcionJuego();
    principalMenu();
}

void marquesina(std::string text, size_t limit) {
	while (true)
	{
		std::string temp = text;
		text.erase(0, 1);text += temp[0];
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		SetConsoleTitleA(text.substr(0, limit).c_str());
	}
}

void DrwImage(std::string imagePath, HDC* console) {

    BMP image;
    image.ReadFromFile(imagePath.c_str());
    //image.SetBitDepth(32);
    for (int x = 0; x < image.TellWidth(); x++)
    {
        for (int y = 0; y < image.TellHeight(); y++)
        {
            int RED = image.GetPixel(x, y).Red;
            int GREEN = image.GetPixel(x, y).Green;
            int BLUE = image.GetPixel(x, y).Blue;

            int ALPHA = image.GetPixel(x, y).Alpha;

            COLORREF COLOUR = RGB(RED, GREEN, BLUE);
            if (ALPHA == 0) {
                SetPixel(*console, x, y, COLOUR);
            }
        }
    }
}

int main()
{
    //Creo directorios de los archivos
    _mkdir("C:\\DamasChinas\\");
    _mkdir("C:\\DamasChinas\\partidas\\");
    //Mensaje a imprimirse en la marquesina
    std::string str = " UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";

    //Creo hilo de ejecucion de marquesina 
    std::thread hilo(marquesina, str, str.size());

    //Dar formato a consola
    ajustarVentana();
    char key;
    HWND console = GetConsoleWindow();
    //Get a handle to console
    HDC dc = GetDC(console);

    cout << "   Pulse enter para salir....";
    while (true) {
        DrwImage("d_1.bmp", &dc);
        key = _getch();
        //if(key == 'w') cout<<"w";
        if (key == 13) {
            cout << "ok" << endl;
            break;
        }
    }
    //Menu de login
    pedirDatos();
    //Menu principal de juego
    principalMenu();

}

void ajustarVentana()
{
	CONSOLE_FONT_INFOEX consola;
	consola.cbSize = sizeof consola;consola.dwFontSize.Y = 24;
	consola.FontFamily = FF_DONTCARE; consola.nFont = 0; consola.FontWeight = FW_NORMAL;
	wcscpy(consola.FaceName, L"Consolas"); SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &consola);
	HWND console_wnd = GetConsoleWindow(); RECT ConsoleRect;
	GetWindowRect(console_wnd, &ConsoleRect); MoveWindow(console_wnd, ConsoleRect.left, ConsoleRect.top, 900, 600, TRUE);
}

