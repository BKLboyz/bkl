#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct node
{
    char label[50];
    int ch_count;
    struct node *child[10];
} *root;

/*
 * Class Declaration
 */
class GT
{
public:
    void create_tree();
    void display(node *r1);
    GT()
    {
        root = NULL;
    }
};

void GT::create_tree()
{
    int tbooks, tchapters, i, j;
    root = new node;
    cout << "Enter name of book: ";
    cin >> root->label;
    cout << "Enter no. of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter Chapter name: ";
        cin >> root->child[i]->label;
        cout << "Enter no. of sections in Chapter " << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count;
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1 << " name: ";
            cin >> root->child[i]->child[j]->label;
        }
    }
}

void GT::display(node *r1)
{
    int i, j, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy---\n";
        cout << "Book title: " << r1->label << endl;
        tchapters = r1->ch_count;
        for (i = 0; i < tchapters; i++)
        {
            cout << "Chapter " << i + 1 << ": " << r1->child[i]->label << endl;
            cout << "Sections:\n";
            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "  Section " << j + 1 << ": " << r1->child[i]->child[j]->label << endl;
            }
        }
    }
}

int main()
{
    int choice;
    GT gt;
    while (1)
    {
        cout << "-----------------\n";
        cout << "Book Tree Creation\n1. Create\n2. Display\n3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;
        case 2:
            gt.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "Wrong choice\n";
        }
    }
    return 0;
}
