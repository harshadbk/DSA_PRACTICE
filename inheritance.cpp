#include <iostream>
using namespace std;

class SingleParent {
public:
    void displaySingleParent() {
        cout << "\n[Single Inheritance]\nParent class function called." << endl;
    }
};

class SingleChild : public SingleParent {
public:
    void displaySingleChild() {
        cout << "Child class function called." << endl;
    }
};

class Base1 {
public:
    void showBase1() {
        cout << "\n[Multiple Inheritance]\nClass Base1 function called." << endl;
    }
};

class Base2 {
public:
    void showBase2() {
        cout << "Class Base2 function called." << endl;
    }
};

class DerivedMultiple : public Base1, public Base2 {
public:
    void showDerivedMultiple() {
        cout << "Derived class from Base1 and Base2 function called." << endl;
    }
};

class GrandParent {
public:
    void showGrandParent() {
        cout << "\n[Multilevel Inheritance]\nGrandParent class function called." << endl;
    }
};

class Parent : public GrandParent {
public:
    void showParent() {
        cout << "Parent class function called." << endl;
    }
};

class Child : public Parent {
public:
    void showChild() {
        cout << "Child class function called." << endl;
    }
};

class HierParent {
public:
    void showHierParent() {
        cout << "\n[Hierarchical Inheritance]\nParent class function called." << endl;
    }
};

class Child1 : public HierParent {
public:
    void showChild1() {
        cout << "Child1 class function called." << endl;
    }
};

class Child2 : public HierParent {
public:
    void showChild2() {
        cout << "Child2 class function called." << endl;
    }
};

class A {
public:
    void showA() {
        cout << "\n[Hybrid Inheritance]\nClass A function called." << endl;
    }
};

class B : public A {
public:
    void showB() {
        cout << "Class B derived from A function called." << endl;
    }
};

class C {
public:
    void showC() {
        cout << "Class C function called." << endl;
    }
};

// D derived from both B (which already inherits A) and C
class D : public B, public C {
public:
    void showD() {
        cout << "Class D derived from B and C function called." << endl;
    }
};

int main() {
    cout << "===== Demonstration of All Types of Inheritance =====\n";

    // 1️⃣ Single Inheritance
    SingleChild sc;
    sc.displaySingleParent();
    sc.displaySingleChild();

    // 2️⃣ Multiple Inheritance
    DerivedMultiple dm;
    dm.showBase1();
    dm.showBase2();
    dm.showDerivedMultiple();

    // 3️⃣ Multilevel Inheritance
    Child mlc;
    mlc.showGrandParent();
    mlc.showParent();
    mlc.showChild();

    // 4️⃣ Hierarchical Inheritance
    Child1 h1;
    Child2 h2;
    h1.showHierParent();
    h1.showChild1();
    h2.showHierParent();
    h2.showChild2();

    // 5️⃣ Hybrid Inheritance
    D hybridObj;
    hybridObj.showA();
    hybridObj.showB();
    hybridObj.showC();
    hybridObj.showD();

    cout << "\n===== End of Demonstration =====\n";
    return 0;
}
