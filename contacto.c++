#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact
{
    std::string name;
    std::string phone;
    std::string email;
};

void addContact(std::vector<Contact> &contacts)
{
    Contact newContact;
    std::cout << "Ingrese su nombre: ";
    std::cin >> newContact.name;
    std::cout << "Ingrese su numero de telefono: ";
    std::cin >> newContact.phone;
    std::cout << "Ingrese su correo electronico: ";
    std::cin >> newContact.email;
    contacts.push_back(newContact);
    std::cout << "Contacto agregado con exito." << std::endl;
}

void displayContacts(const std::vector<Contact> &contacts)
{
    for (const auto &contact : contacts)
    {
        std::cout << "Nombre: " << contact.name << ", Telefono: " << contact.phone << ", Correo: " << contact.email << std::endl;
    }
}

void searchContact(const std::vector<Contact> &contacts)
{
    std::string searchTerm;
    std::cout << "Introduce el nombre que quieres buscar: ";
    std::cin >> searchTerm;

    bool found = false;
    for (const auto &contact : contacts)
    {
        if (contact.name == searchTerm)
        {
            std::cout << "Nombre: "
                      << contact.name << ", Telefono: "
                      << contact.phone << ", Correo: "
                      << contact.email << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Contacto no encontrado." << std::endl;
    }
}

void deleteContact(std::vector<Contact> &contacts)
{
    std::string nameToDelete;
    std::cout << "Ingrese el nombre del contacto que quieres eliminar: ";
    std::cin >> nameToDelete;
    auto it = std::remove_if(contacts.begin(),
                             contacts.end(), [&](const Contact &contact)
                             { return contact.name == nameToDelete; });

    if (it != contacts.end())
    {
        contacts.erase(it, contacts.end());
        std::cout << "Contacto eliminado." << std::endl;
    }
    else
    {
        std::cout << "Contacto no encontrado." << std::endl;
    }
}

int main()
{
    std::vector<Contact> contacts;
    int choice;

    do
    {
        std::cout << "\n1, Agregar Contacto" << std::endl;
        std::cout << "2. Ver Contactos" << std::endl;
        std::cout << "3. Buscar Contacto" << std::endl;
        std::cout << "4. Eliminar Contacto" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Introduzca su elección: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayContacts(contacts);
            break;
        case 3:
            searchContact(contacts);
            break;
        case 4:
            deleteContact(contacts);
            break;
        case 5:
            break;
        default:
            std::cout << "Selección Invalidad."
                      << std::endl;
        }
    } while (choice != 5);

    return 0;
}