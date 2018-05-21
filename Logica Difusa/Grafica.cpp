#include "Grafica.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LogicaDifusa::Grafica form;
	Application::Run(%form);

}

System::Void LogicaDifusa::Grafica::pictureBox1_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	//Inicializo
	mylapiz1 = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	mylapiz2 = gcnew System::Drawing::Pen(System::Drawing::Color::Red);

	//Ejes 0,0
	int xcentro = pictureBox1->Width / 2;
	int ycentro = pictureBox1->Height / 2;

	e->Graphics->TranslateTransform(xcentro,ycentro);
	e->Graphics->ScaleTransform(1,-1);

	//Se dibuja el eje X e Y
	e->Graphics->DrawLine(mylapiz1,xcentro * -1,0,xcentro * 2,0);//Eje X
	e->Graphics->DrawLine(mylapiz2,0,ycentro,0,ycentro * -1);
}
