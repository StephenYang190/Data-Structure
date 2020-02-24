//
// Created by 97927 on 2019/12/21.
//
bool midToOut(string str,stack<char> * oprt1,stack<char> *oprt2)
{
    int i = str.find('#');
    while(i < str.length() && i != string::npos)
    {
        if(str[i] == '#')
        {
            i++;
            continue;
        }

        if(str[i] >= '0' && str[i] <= '9')
        {
            oprt2.push('|');
            int pause = i;
            while(str[pause] == ' ' || (str[pause] >= '0' && str[pause] <= '9'))
            {
                pause++;
            }
            int i_pause = pause;
            pause--;
            while(pause >= i)
            {
                if(str[pause] != ' ')
                {
                    oprt2.push(str[pause]);
                }
                pause--;
            }
            oprt2.push('|');
            i = i_pause;
            continue;
        } else if(str[i] == ' '){

        }else if(str[i] == ')')
        {
            char pause = oprt1.top();
            while(pause != '(')
            {
                oprt2.push(pause);
                oprt1.pop();
                pause = oprt1.top();
            }
            oprt1.pop();
        }else{
            char pause;
            if(!oprt1.empty())
                pause = oprt1.top();
            if(oprt1.empty() || pause == '(')
            {
                oprt1.push(str[i]);
            } else if(compareOperate(pause,str[i]))
            {
                oprt1.push(str[i]);
            } else{
                while(!compareOperate(pause,str[i]))
                {
                    oprt2.push(pause);
                    oprt1.pop();
                    pause = oprt1.top();
                }
                oprt2.push(str[i]);
            }
        }
        i++;
    }
    while(!oprt1.empty())
    {
        oprt2.push(oprt1.top());
        oprt1.pop();
    }
    return i != string::npos;
}
int main()
{
    std::string str = getString("calculation(below 20,ignore all blanket)");
    stack<char> oprt1;
    stack<char> oprt2;
    my_stack nmb;
    cout<<str<<endl;
    midToOut(str,&oprt1,&oprt2);
    while(!oprt2.empty())
    {
        cout<<oprt2.top();
        oprt2.pop();
    }
    cout<<endl;

    return 0;
}