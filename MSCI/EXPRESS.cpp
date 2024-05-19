#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

struct element
{
    char data;
    int level;

    element(char c, int lv) : data(c), level(lv) {}
    bool operator<(element x) const
    {
        return level>x.level;
    }
};


// node
struct node
{
    char data;
    node *l, *r;

    node(char c, node *pl, node *pr) : data(c), l(pl), r(pr) {}

    // clear()
    static node* clear(node *root)
    {
        if(root)
        {
            root->l = clear(root->l);
            root->r = clear(root->r);
            delete root;
        }

        return NULL;
    }

    // walk()
    static void walk(node *root, int level, vector<element>& visited)
    {
        if(root)
        {
            walk(root->l, level+1, visited);
            walk(root->r, level+1, visited);
            visited.push_back( element(root->data, level) );
        }
    }
};

int main()
{
    int t;
    string line;

    getline(cin, line);
    sscanf(line.c_str(), "%d", &t);
    while(t--)
    {
        char *p;
        stack<node*> s;

        // input
        getline(cin, line);
        for(p=(char*)line.c_str(); *p; p++)
        {
            if(isupper(*p))
            {
                node *l, *r;

                l = s.top();
                s.pop();

                r = s.top();
                s.pop();

                s.push(new node(*p, l, r));
            }
            else
                s.push(new node(*p, NULL, NULL));
        }
        node *root = s.top();
        vector<element> visited;
        node::walk(root, 0, visited);

        // output
        stable_sort(visited.begin(), visited.end());
        for(int i=0; i<(int)visited.size(); i++)
            putchar( visited[i].data );
        putchar('\n');

        root = node::clear(root);
    }

    return 0;
}
