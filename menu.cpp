#include <iostream>
#include <string>
#include <vector>

class Obra
{
public:
  std::string nombre;
  std::string fecha;

public:
  Obra(const std::string& nombre, const std::string& fecha) : nombre(nombre), fecha(fecha)
  {
    std::cout << "Se ha creado la obra " << nombre << " en la fecha de " << fecha << std::endl;
  }

  ~Obra()
  {
    std::cout << "Se ha eliminado la obra " << nombre << std::endl;
  }
};

class Artista
{
public:
  std::string nombre;
  int edad;
  std::vector<Obra*> obrasContainer;

public:
  Artista(const std::string& nombre, int edad) : nombre(nombre), edad(edad)
  {
    std::cout << "Se ha creado el artista " << nombre << " de edad " << edad << std::endl;
  }

  ~Artista()
  {
    std::cout << "Se ha eliminado el artista " << nombre << std::endl;

    for (auto obra : obrasContainer)
    {
      delete obra;
    }
  }

  Artista& agregarObra(Obra* obra)
  {
    obrasContainer.push_back(obra);
    return *this;
  }

  Artista& crearObra()
 {
  std::string nombre, fecha;
  std::cout << "Elija el nombre de la obra: ";
  std::cin >> nombre;
  std::cout << "Elija la fecha: ";
  std::cin >> fecha;
  Obra* nuevaObra = new Obra(nombre, fecha);
  agregarObra(nuevaObra);
  return *this;
 }
};

int main()
{
  std::vector<Artista*> artistas;
  int opcion;

  do
  {
    std::cout << " MENU DE OPCIONES"  << std::endl;
    std::cout << "1. Agregar artista" << std::endl;
    std::cout << "2. Crear obra" << std::endl;
    std::cout << "3. Ver obras de un artista" << std::endl;
    std::cout << "4. Salir del programa" << std::endl;
    std::cout << "Elija una opcion: ";
    std::cin >> opcion;
    switch (opcion)
    {
      case 1:
      {
        std::string nombre;
        int edad;
        std::cout << "Ingrese el nombre del artista: ";
        std::cin >> nombre;
        std::cout << "Ingrese la edad del artista: ";
        std::cin >> edad;
        artistas.push_back(new Artista(nombre, edad));
        break;
      }
case 2:
{
  int artistaIndex;
  std::cout << "Seleccione el artista que va a crear la obra:" << std::endl;

  for (int i = 0; i < artistas.size(); i++)
  {
    std::cout << i + 1 << ". " << artistas[i]->nombre << std::endl;
  }

  std::cout << "Elija una opcion: ";
  std::cin >> artistaIndex;

  artistas[artistaIndex - 1]->crearObra();
  break;
}
case 3:
{
  int artistaIndex;
  std::cout << "Seleccione el artista cuyas obras quiere ver:" << std::endl;

  for (int i = 0; i < artistas.size(); i++)
  {
    std::cout << i + 1 << ". " << artistas[i]->nombre << std::endl;
  }

  std::cout << "Elija una opcion: ";
  std::cin >> artistaIndex;

  // Verificar si el índice del artista es válido
  if (artistaIndex < 1 || artistaIndex > artistas.size())
  {
    std::cout << "Índice de artista inválido." << std::endl;
    break;
  }

  Artista *artista = artistas[artistaIndex - 1];
  std::cout << "Obras de " << artista->nombre << ":" << std::endl;

  for (int i = 0; i < artista->obrasContainer.size(); i++)
  {
    std::cout << artista->obrasContainer[i]->nombre << " (" << artista->obrasContainer[i]->fecha << ")" << std::endl;
  }
  break;
}
case 4:
{
  std::cout << "Fin del Programa" << std::endl;

  // Liberar memoria de los artistas y sus obras
  for (int i = 0; i < artistas.size (); i++)
  {
    delete artistas[i];
  }
  artistas.clear(); // Limpiar el vector

  break;
}
}
} while (opcion != 4);

// Liberar memoria
for (int i = 0; i < artistas.size (); i++)
{
delete artistas[i];
}

return 0;
}