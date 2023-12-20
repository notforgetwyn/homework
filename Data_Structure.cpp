#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
string FileTitle[100];//储存文件的标题
string File[100][100];//储存第i个文件第j行
const int MAX_TABLE_SIZE = 300009;
struct  ValueNode
{
    int FileTopic;
    set<int> FileLine;
};
struct HashNode
{
    int LastFile;
    int LastLine;
    string Key_Node;
    vector< ValueNode>  Value_Node;
};
/*Hash*/
struct HashTable
{
    int TableSize;
    HashNode* Hash_Node;
};
typedef struct HashTable* Hash_Table;
Hash_Table CreateTable()
{

    Hash_Table H = new HashTable;
    H->TableSize = MAX_TABLE_SIZE;
    H->Hash_Node = new  HashNode[MAX_TABLE_SIZE];
    for (int i = 0; i < H->TableSize; i++)
    {
        H->Hash_Node[i].LastFile = -1;
        H->Hash_Node[i].LastLine = -1;
    }
    return H;
}
int Hash(string Key_Node, int TableSize)
{
    int  len = 0, N = 0;
    unsigned int h = 0;
    for (int i = 0; i < N; i++)
    {
        h = (h << 5) + (Key_Node[i] - 'a');
    }
    return (h & (32 * 32 * 32 - 1)) % TableSize;
}
int Find(Hash_Table H, string Key_Node)//线形探测法解决冲突
{
    int New_Position, Cur_Position, Num = 0;//Num表示冲突次数
    New_Position = Cur_Position = Hash(Key_Node, H->TableSize);
    while ((H->Hash_Node[New_Position].LastFile != -1) && (H->Hash_Node[New_Position].Key_Node != Key_Node))
    {
        Num++;
        New_Position = Cur_Position + Num;
        if (New_Position >= H->TableSize)
            New_Position -= H->TableSize;
    }
    return New_Position;
}
void Insert(Hash_Table H, string Key_Node, int File, int FileLine)
{
    ValueNode* temp;
    int position = Find(H, Key_Node);
    if (H->Hash_Node[position].LastFile == -1)//表示这个位置为空,那么要先插入单词，再插入文件和行号
    {
        H->Hash_Node[position].LastFile = File;
        H->Hash_Node[position].LastLine = FileLine;
        H->Hash_Node[position].Key_Node = Key_Node;//printf("插入了%s\n",Key_Node.c_str());
        temp = new  ValueNode;
        temp->FileTopic = File; temp->FileLine.insert(FileLine);
        H->Hash_Node[position].Value_Node.push_back(*temp);
    }
    else if (H->Hash_Node[position].LastFile != File)
    {
        H->Hash_Node[position].LastFile = File;
        H->Hash_Node[position].LastLine = FileLine;
        temp = new  ValueNode;
        temp->FileTopic = File; temp->FileLine.insert(FileLine);
        H->Hash_Node[position].Value_Node.push_back(*temp);
    }
    else if (H->Hash_Node[position].LastLine != FileLine)
    {
        H->Hash_Node[position].Value_Node[H->Hash_Node[position].Value_Node.size() - 1].FileLine.insert(FileLine);
    }
}
/*Hash*/
void readFile(Hash_Table H)
{
    int N;
    cin >> N;
    string File_Context;
    char* Temp_File_Context, * File_Context_Word;
    getchar();
    for (int i = 0; i < N; i++)//i是文件的编号从0~N-1
    {
        getline(cin, FileTitle[i]); int j = 0;//j代表行号

        while (getline(cin, File_Context), File_Context != "#")
        {
            File[i][j] = File_Context;

            Temp_File_Context = new char[File_Context.size() + 1];
            strcpy(Temp_File_Context, File_Context.c_str());
            File_Context_Word = strtok(Temp_File_Context, " ");

            while (File_Context_Word != NULL)
            {
                for (int k = 0; k < strlen(File_Context_Word); k++)
                {
                    if ((File_Context_Word[k] >= 'A') && (File_Context_Word[k] <= 'Z'))
                    {
                        File_Context_Word[k] = File_Context_Word[k] + 32;
                    }
                }
                Insert(H, File_Context_Word, i, j);
                File_Context_Word = strtok(NULL, " ");
            }
            j++;
        }
    }
}
void insert_section(vector< ValueNode>& v1, vector< ValueNode>& v2, vector< ValueNode>& v)
{
    vector< ValueNode>::iterator it1, it2;
    set<int>::iterator it3, it4;
    it1 = v1.begin(); it2 = v2.begin();
    while (it1 != v1.end() && it2 != v2.end())
    {
        if (it1->FileTopic == it2->FileTopic)
        {
            ValueNode* temp = new  ValueNode;
            temp->FileTopic = it1->FileTopic;
            for (it3 = it1->FileLine.begin(); it3 != it1->FileLine.end(); it3++)
            {
                temp->FileLine.insert(*it3);
            }
            for (it4 = it2->FileLine.begin(); it4 != it2->FileLine.end(); it4++)
            {
                temp->FileLine.insert(*it4);
            }
            v.push_back(*temp);
            it1++; it2++;
        }
        else if (it1->FileTopic < it2->FileTopic)
        {
            it1++;
        }
        else
        {
            it2++;
        }
    }
}
void Query(Hash_Table H)
{
    string File_Context, Query_Word[10];
    char* Temp_File_Context, * File_Context_Word;
    getline(cin, File_Context);
    Temp_File_Context = new char[File_Context.size() + 1];
    strcpy(Temp_File_Context, File_Context.c_str());
    File_Context_Word = strtok(Temp_File_Context, " ");//printf("%s\n", File_Context_Word);
    int Num = 0;
    while (File_Context_Word != NULL)
    {
        for (int k = 0; k < strlen(File_Context_Word); k++)
        {
            if ((File_Context_Word[k] >= 'A') && (File_Context_Word[k] <= 'Z'))
            {
                File_Context_Word[k] = File_Context_Word[k] + 32;
            }
        }
        Query_Word[Num] = File_Context_Word;//cout<<Query_Word[Num]<<endl;
        Num++;
        File_Context_Word = strtok(NULL, " ");
    }
    vector< ValueNode> vi; int position; vector< ValueNode> v;
    for (int i = 0; i < Num; i++)
    {
        position = Find(H, Query_Word[i]);//cout<<"单词是"<<H-> Hash_Node[position].Key_Node<<endl;
        if (i == 0)
        {
            vi.insert(vi.begin(), H->Hash_Node[position].Value_Node.begin(), H->Hash_Node[position].Value_Node.end());
        }
        else
        {
            insert_section(vi, H->Hash_Node[position].Value_Node, v);
            vi.clear();
            vi.insert(vi.begin(), v.begin(), v.end());
            v.clear();
        }
        
        cout << "该查询单词" << Query_Word[i] << "的文件总数" << vi.size()<<" ";
        if (vi.size() == 0)
        {
            printf("---Not Found");
           
           
        }
        else
        {
            cout << "---该查询单词的所在文档的标题";
        }
        for (auto it = vi.begin(); it != vi.end(); it++)
        {
            
            printf("%s ", FileTitle[it->FileTopic].c_str());
            
        }
        cout << endl;
       
    }
}
int main()
{
    int flag;
    cout << "***** 迷你搜索引擎 *****" << endl;
    cout << "------------------------" << endl;
    cout << "-------开始程序---------" << endl;
    cout << "------------------------" << endl;
    cout << "------------------------" << endl;
    cout << "文档内容由文件读取" << endl;
    Hash_Table H = CreateTable();
    readFile(H);
    cout << endl;
    cout << "请输入M代表搜索的行数，搜索的关键字由文档读取" << endl;
    int M;
    cin >> M;
    getchar();
    for (int i = 0; i < M; i++)
    {
        Query(H);
        cout << endl;
    }
    return 0;
}
