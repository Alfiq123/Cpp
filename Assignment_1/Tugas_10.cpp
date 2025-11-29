#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Folder {
public:
    string nama;
    vector<Folder *> children;

    Folder(string nama) {
        this->nama = nama;
    }

    void tambahChild(Folder *child) {
        children.push_back(child);
    }

    void display(int level = 0) {
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        cout << "- " << nama << endl;

        for (Folder *child: children) {
            child->display(level + 1);
        }
    }
};

int main() {
    Folder *root = new Folder("C:");

    Folder *dokumen = new Folder("Dokumen");
    Folder *gambar = new Folder("Foto-Foto");

    root->tambahChild(dokumen);
    root->tambahChild(gambar);

    dokumen->tambahChild(new Folder("Resume"));
    dokumen->tambahChild(new Folder("Report"));

    gambar->tambahChild(new Folder("Foto Liburan"));
    gambar->tambahChild(new Folder("Foto Keluarga"));

    root->display();

    return 0;
}
