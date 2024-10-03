#include <iostream>
#include <cstring>  
#include <cstdlib>  
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


struct node {
    char inf[256];  
    node* next;      
};

node* head = nullptr, * last = nullptr;  

void spstore();   
void review();     
node* get_struct(); 


node* get_struct() {
    setlocale(LC_ALL, "Rus");
    node* p = nullptr;
    char s[256];

    p = new node; 

    if (!p) {
        std::cerr << "Ошибка при распределении памяти\n";
        exit(1);
    }

    cout << "Введите название объекта: \n";
    cin >> s;  
    if (s[0] == '\0') {
        cout << "Запись не была произведена\n";
        return nullptr;
    }
    strcpy_s(p->inf, sizeof(p->inf), s);  

    p->next = nullptr;
    return p; 
}


void spstore() {
    node* p = get_struct();
    if (p == nullptr) return;

    // Если список пуст
    if (head == nullptr) {
        head = p;
        last = p;
    }
    else {
        
        if (strcmp(p->inf, head->inf) < 0) {
            p->next = head;
            head = p;
        }
        else {
           
            node* current = head;
            while (current->next != nullptr && strcmp(p->inf, current->next->inf) >= 0) {
                current = current->next;
            }

           
            p->next = current->next;
            current->next = p;

         
            if (p->next == nullptr)
                last = p;
        }
    }
}


void review() {
    setlocale(LC_ALL, "Rus");
    node* struc = head;
    if (head == nullptr) {
        cout << "Список пуст\n";
    }
    while (struc) {
        cout << "Имя - " << struc->inf << "\n";  
        struc = struc->next;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    do {
        cout << "1. Добавить объект\n2. Просмотреть список\n3. Выход\n";
        cin >> choice;

        switch (choice) {
        case 1:
            spstore();  
            break;
        case 2:
            review();  
            break;
        case 3:
            cout << "Завершение программы...\n";
            break;
        default:
            cout << "Попробуй снова.\n";
        }
    } while (choice != 3);  

    return 0;
}
