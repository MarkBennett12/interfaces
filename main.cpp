#include <iostream>

using namespace std;

class Renderer
{
protected:
    int n;
public:

    virtual void Draw()=0;
};

class GLRenderer:Renderer
{
    public:
    void Draw(){/**/cout<<"Drawing OpenGL" << endl;};
};

class DXRenderer:Renderer
{
    public:
    void Draw(){/**/cout<<"Drawing DirectX" << endl;};
};

void* GetRenderer(int choice)
{
    if (choice == 1)
        //GLRenderer* myGLRenderer = new GLRenderer();
        return new GLRenderer();
    else if(choice == 2)
        //DXRenderer* mydxRenderer = new DXRenderer();
        return new DXRenderer();
    else
        cout << "invalid choice" << endl;
}

void Run(void *r)
{
    Renderer* render = static_cast<Renderer*>(r);
    render->Draw();
}

int main()
{
    int choice = 0;
    cout << "Do you want to use OpenGL (1) or DirextX (2)" << endl;

    cin >> choice;

    Run(GetRenderer(choice));

    float choiceAsFloat = (float)choice + 0.1;
    cout << "Your choice as a float " << choiceAsFloat << endl;

    return 0;
}
