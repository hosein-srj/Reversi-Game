#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <string>
#include <sstream>

std::string to_str(int i)
{
    std::stringstream ss;
    ss << i;

    std::string result(ss.str());

    return result;
}
int mokhtasaty(int y)
{

    if(y>50&&y<112.5)
    {
        return 0;
    }
    else if(y>112.5&&y<175)
    {
        return 1;
    }
    else if(y>175&&y<237.5)
    {
        return 2;
    }
    else if(y>237.5&&y<300)
    {
        return 3;
    }
    else if(y>300&&y<362.5)
    {
        return 4;
    }
    else if(y>362.5&&y<425)
    {
        return 5;
    }
    else if(y>425&&y<487.5)
    {
        return 6;
    }
    else if(y>487.5&&y<550)
    {
        return 7;
    }
}
int mokhtasatx(int x)
{

    if(x>372.5&&x<434.5)
    {
        return 0;
    }
    else if(x>434.5&&x<497.5)
    {
        return 1;
    }
    else if(x>497.5&&x<559.5)
    {
        return 2;
    }
    else if(x>559.5&&x<622)
    {
        return 3;
    }
    else if(x>622&&x<684.5)
    {
        return 4;
    }
    else if(x>684.5&&x<747)
    {
        return 5;
    }
    else if(x>747&&x<809.5)
    {
        return 6;
    }
    else if(x>809.5&&x<872)
    {
        return 7;
    }
}
int main()
{
    unsigned int pos=0;
    int x1,y1;
    int pauses=0,pauses2=0;
    int ezafex,ezafey;
    int sht=4;
    int nahai=64;
    char z[8][8]={ {' ',' ',' ',' ',' ',' ',' ',' '},
				   {' ',' ',' ',' ',' ',' ',' ',' '},
				   {' ',' ',' ',' ',' ',' ',' ',' '},
				   {' ',' ',' ',' ',' ',' ',' ',' '},
				   {' ',' ',' ',' ',' ',' ',' ',' '},
				   {' ',' ',' ',' ',' ',' ',' ',' '},
				   {' ',' ',' ',' ',' ',' ',' ',' '},
				   {' ',' ',' ',' ',' ',' ',' ',' '}
				 };

    z[3][3]='W';
    z[4][4]='W';
    z[3][4]='B';
    z[4][3]='B';
    int rond;
    int a,b;
    int meqdarWhite=2,meqdarBlack=2,tafriq1,tafriq2;
    sf::Font font;
    if (!font.loadFromFile("CURLZ___.TTF"))
        return -1;
    sf::Text text1;
    sf::Text text2;
    sf::Text ee;
    sf::Text biharekat;
    text1.setFont(font);
    text2.setFont(font);
    sf::Text payan;
    sf::Music music;
    if (!music.openFromFile("Tabl.ogg"))
        return -1;

    sf::Texture texture,texture2;
    if (!texture.loadFromFile("texture.png"))
        return -1;
    if (!texture2.loadFromFile("texture2.png"))
        return -1;
    sf::Sprite sprite,sprite2;
    sprite.setTexture(texture);
    sprite2.setTexture(texture2);
    sf::RenderWindow window(sf::VideoMode(1244, 700), "Reversi");
    rond=0;
    int m=0,n=0;
    while(m<8)
    {
        while(n<8)
        {
            if(z[m][n]=='W')
                rond++;
            if(z[m][n]=='B')
                rond++;
            n++;
        }
        n=0;
        m++;
    }
    while (window.isOpen())
    {


        while(pauses2==0)
        {
            window.clear();
            sf::Text play,welcome;
            play.setString("PLAY");
            play.setFont(font);
            play.setColor(sf::Color::Yellow);
            play.setCharacterSize(100);
            play.setPosition(490,300);
            welcome.setString("Welcome To Reversi");
            welcome.setFont(font);
            welcome.setColor(sf::Color::Yellow);
            welcome.setCharacterSize(110);
            welcome.setPosition(190,100);
            sf::Event event3;
            while (window.pollEvent(event3))
            {
                if (event3.type == sf::Event::Closed)
                    window.close();
                if ( event3.type == sf::Event::MouseMoved )
                {
                    x1=event3.mouseMove.x;
                    y1=event3.mouseMove.y;


                }
                if(event3.type==sf::Event::MouseButtonPressed)
                {
                    if(event3.mouseButton.button==sf::Mouse::Left)
                    {

                        if(x1>490&&x1<730&&y1>320&&y1<420)
                            pauses2=1;
                    }
                }
            }
            if(x1>490&&x1<730&&y1>320&&y1<420)
            {
                play.setStyle(sf::Text::Bold | sf::Text::Underlined );
                play.setColor(sf::Color::Red);
            }
            window.draw(sprite2);
            window.draw(play);
            window.draw(welcome);



            window.display();
        }



        while(1)
        {
            window.clear();
            sf::Event event;
            while (window.pollEvent(event))
            {


                if(event.type==sf::Event::MouseMoved)
                {
                    x1=event.mouseMove.x;
                    y1=event.mouseMove.y;
                }
                if(event.type==sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button==sf::Mouse::Left)
                    {
                        int x2,y2;
                        x2=event.mouseButton.x;
                        y2=event.mouseButton.y;
                        if(x1>1000&&x1<1160&&y1>330&&y1<380)
                        {
                            int pp=0;
                            int ppp=0;
                            while(ppp<8)
                            {
                                while(pp<8)
                                {
                                    z[pp][ppp]=' ';
                                    pp++;
                                }
                                pp=0;
                                ppp++;
                            }
                            payan.setString(" ");
                            pauses=0;
                            z[3][3]='W';
                            z[4][4]='W';
                            z[3][4]='B';
                            z[4][3]='B';
                            sht=3;
                            nahai=64;
                        }
                    }
                }



                if (event.type == sf::Event::Closed)
                    window.close();
                if(pauses==0)
                {
                    if (event.type==sf::Event::MouseButtonPressed)
                    {
                        if(event.mouseButton.button==sf::Mouse::Left)
                        {
                            int x,y,hold;
                            x=event.mouseButton.x;
                            y=event.mouseButton.y;
                            x=mokhtasatx(x);
                            y=mokhtasaty(y);
                            hold=x;
                            x=y;
                            y=hold;
                            int check,checkx,checky;
                            if(sht%2==1)
                            {
                                if( z[x][y]!='W' && z[x][y]!='B')
                                {

                                    if( (z[x][y-1]=='W') )
                                    {
                                        check=y-2;
                                        while(check>=0 )
                                        {
                                            if(z[x][check]=='B')
                                                break;
                                            else if(z[x][check]!='W')
                                            {
                                                check=-1;
                                                break;
                                            }
                                            else
                                                check--;
                                        }
                                        if (check>=0)
                                        {
                                            while(check<y)
                                            {
                                                z[x][check+1]='B';
                                                check++;
                                            }
                                        }
                                    }
                                    if( (z[x-1][y-1]=='W') )
                                    {
                                        checky=y-2;
                                        checkx=x-2;
                                        while(checkx>=0 && checky>=0 )
                                        {
                                            if(z[checkx][checky]=='B')
                                                break;
                                            else if(z[checkx][checky]!='W')
                                            {
                                                checky=-1;
                                                break;
                                            }
                                            else
                                            {
                                                checkx--;
                                                checky--;
                                            }
                                        }
                                        if (checkx>=0 && checky>=0)
                                        {
                                            while(checky<y)
                                            {
                                                z[checkx+1][checky+1]='B';
                                                checkx++;
                                                checky++;
                                            }
                                        }
                                    }
                                    if( (z[x-1][y]=='W') )
                                    {
                                        check=x-2;
                                        while(check>=0 )
                                        {
                                            if(z[check][y]=='B')
                                                break;
                                            else if(z[check][y]!='W')
                                            {
                                                check=-1;
                                                break;
                                            }
                                            else
                                                check--;
                                        }
                                        if (check>=0)
                                        {
                                            while(check<x)
                                            {
                                                z[check+1][y]='B';
                                                check++;
                                            }
                                        }
                                    }
                                    if( z[x+1][y-1]=='W' )
                                    {
                                        checky=y-2;
                                        checkx=x+2;
                                        while(checkx<8 && checky>=0 )
                                        {
                                            if(z[checkx][checky]=='B')
                                                break;
                                            else if(z[checkx][checky]!='W')
                                            {
                                                checky=-1;
                                                break;
                                            }
                                            else
                                            {
                                                checkx++;
                                                checky--;
                                            }
                                        }
                                        if (checkx<8 && checky>=0)
                                        {
                                            while(checky<y)
                                            {
                                                z[checkx-1][checky+1]='B';
                                                checkx--;
                                                checky++;
                                            }
                                        }
                                    }
                                    if(z[x+1][y]=='W')
                                    {
                                        check=x+2;
                                        while(check<8 )
                                        {
                                            if(z[check][y]=='B')
                                                break;
                                            else if(z[check][y]!='W')
                                            {
                                                check=9;
                                                break;
                                            }
                                            else
                                                check++;
                                        }
                                        if (check<8)
                                        {
                                            while(check>x)
                                            {
                                                z[check-1][y]='B';
                                                check--;
                                            }
                                        }
                                    }
                                    if( z[x+1][y+1]=='W' )
                                    {
                                    checky=y+2;
                                    checkx=x+2;
                                    while(checkx<8 && checky<8 )
                                    {
                                        if(z[checkx][checky]=='B')
                                            break;
                                        else if(z[checkx][checky]!='W')
                                        {
                                            checkx=9;
                                            break;
                                        }
                                        else
                                        {
                                            checkx++;
                                            checky++;
                                        }
                                    }
                                    if (checkx<8 && checky<8)
                                        {
                                            while(checky>y)
                                            {
                                                z[checkx-1][checky-1]='B';
                                                checkx--;
                                                checky--;
                                            }
                                        }
                                    }
                                    if(z[x][y+1]=='W')
                                    {
                                    check=y+2;
                                    while(check<8 )
                                    {
                                        if(z[x][check]=='B')
                                            break;
                                        else if(z[x][check]!='W')
                                        {
                                            check=9;
                                            break;
                                        }
                                        else
                                            check++;
                                    }
                                    if (check<8)
                                    {
                                        while(check>y)
                                        {
                                            z[x][check-1]='B';
                                            check--;
                                        }
                                    }
                                }
                                if( z[x-1][y+1]=='W' )
                                {
                                   checky=y+2;
                                   checkx=x-2;
                                   while(checkx>=0 && checky<=8 )
                                   {
                                       if(z[checkx][checky]=='B')
                                            break;
                                        else if(z[checkx][checky]!='W')
                                        {
                                            checkx=-1;
                                            break;
                                        }
                                       else
                                        {
                                            checkx--;
                                            checky++;
                                        }
                                    }
                                       if (checkx>=0 && checky<8)
                                       {
                                            while(checky>y)
                                            {
                                                z[checkx+1][checky-1]='B';
                                                checkx++;
                                                checky--;
                                            }
                                        }
                                   }
                                }
                            }
                            if(sht%2==0)
                            {
                                if( z[x][y]!='W' && z[x][y]!='B')
                                {
                                    if( (z[x][y-1]=='B') )
                                    {
                                        check=y-2;
                                        while(check>=0 )
                                        {
                                            if(z[x][check]=='W')
                                                break;
                                            else if(z[x][check]!='B')
                                            {
                                                check=-1;
                                                break;
                                            }
                                            else
                                                check--;
                                        }
                                        if (check>=0)
                                        {
                                            while(check<y)
                                            {
                                                z[x][check+1]='W';
                                                check++;
                                            }
                                        }
                                    }
                                    if( (z[x-1][y-1]=='B') )
                                    {
                                        checky=y-2;
                                        checkx=x-2;
                                        while(checkx>=0 && checky>=0 )
                                        {
                                            if(z[checkx][checky]=='W')
                                                break;
                                            else if(z[checkx][checky]!='B')
                                            {
                                                checky=-1;
                                                break;
                                            }
                                            else
                                            {
                                                checkx--;
                                                checky--;
                                            }
                                        }
                                        if (checkx>=0 && checky>=0)
                                        {
                                            while(checky<y)
                                            {
                                                z[checkx+1][checky+1]='W';
                                                checkx++;
                                                checky++;
                                            }
                                        }
                                    }
                                    if( (z[x-1][y]=='B') )
                                    {
                                        check=x-2;
                                        while(check>=0 )
                                        {
                                            if(z[check][y]=='W')
                                                break;
                                            else if(z[check][y]!='B')
                                            {
                                                check=-1;
                                                break;
                                            }
                                            else
                                                check--;
                                        }
                                        if (check>=0)
                                        {
                                            while(check<x)
                                            {
                                                z[check+1][y]='W';
                                                check++;
                                            }
                                        }
                                    }
                                    if( z[x+1][y-1]=='B' )
                                    {
                                        checky=y-2;
                                        checkx=x+2;
                                        while(checkx<8 && checky>=0 )
                                        {
                                            if(z[checkx][checky]=='W')
                                                break;
                                            else if(z[checkx][checky]!='B')
                                            {
                                                checkx=9;
                                                break;
                                            }
                                            else
                                            {
                                                checkx++;
                                                checky--;
                                            }
                                        }
                                        if (checkx<8 && checky>=0)
                                        {
                                            while(checky<y)
                                            {
                                                z[checkx-1][checky+1]='W';
                                                checkx--;
                                                checky++;
                                            }
                                        }
                                    }
                                    if(z[x+1][y]=='B')
                                    {
                                        check=x+2;
                                        while(check<8 )
                                        {
                                            if(z[check][y]=='W')
                                                break;
                                            else if(z[check][y]!='B')
                                            {
                                                check=9;
                                                break;
                                            }
                                            else
                                                check++;
                                        }
                                        if (check<8)
                                        {
                                            while(check>x)
                                            {
                                                z[check-1][y]='W';
                                                check--;
                                            }
                                        }
                                    }
                                    if( z[x+1][y+1]=='B' )
                                    {
                                       checky=y+2;
                                       checkx=x+2;
                                       while(checkx<8 && checky<8 )
                                       {
                                            if(z[checkx][checky]=='W')
                                               break;
                                            else if(z[checkx][checky]!='B')
                                            {
                                                checkx=9;
                                                break;
                                            }
                                           else
                                           {
                                               checkx++;
                                            checky++;
                                        }
                                       }
                                       if (checkx<8 && checky<8)
                                        {
                                            while(checky>y)
                                            {
                                                z[checkx-1][checky-1]='W';
                                                checkx--;
                                                checky--;
                                            }
                                        }
                                    }
                                   if(z[x][y+1]=='B')
                                   {
                                       check=y+2;
                                    while(check<8 )
                                    {
                                        if(z[x][check]=='W')
                                            break;
                                        else if(z[x][check]!='B')
                                        {
                                                check=9;
                                                break;
                                        }
                                        else
                                            check++;
                                       }
                                       if (check<8)
                                       {
                                            while(check>y)
                                            {
                                                z[x][check-1]='W';
                                                check--;
                                            }
                                       }
                                   }
                                   if( z[x-1][y+1]=='B' )
                                   {
                                       checky=y+2;
                                       checkx=x-2;
                                       while(checkx>=0 && checky<8 )
                                       {
                                           if(z[checkx][checky]=='W')
                                            break;
                                            else if(z[checkx][checky]!='B')
                                            {
                                                checkx=-1;
                                                break;
                                            }
                                           else
                                           {
                                            checkx--;
                                            checky++;
                                            }
                                      }
                                       if (checkx>=0 && checky<8)
                                       {
                                            while(checky>y)
                                            {
                                                z[checkx+1][checky-1]='W';
                                                checkx++;
                                                checky--;
                                            }
                                        }
                                   }
                                }
                            }
                            tafriq1=meqdarBlack-meqdarWhite;
                            rond=0;
                            meqdarBlack=0;
                            meqdarWhite=0;
                            int m=0,n=0;
                            while(m<8)
                            {
                                while(n<8)
                                {
                                    if(z[m][n]=='W')
                                    {
                                        meqdarWhite++;
                                        rond++;
                                    }
                                    else if(z[m][n]=='B')
                                    {
                                        meqdarBlack++;
                                        rond++;
                                    }
                                    n++;
                                }
                                n=0;
                                m++;
                            }
                            tafriq2=meqdarBlack-meqdarWhite;
                            if(tafriq1!=tafriq2)
                                sht++;


                            if(sht==nahai)
                            {

                                payan.setFont(font);
                                payan.setPosition(365,580);
                                payan.setColor(sf::Color::Cyan);
                                payan.setCharacterSize(50);
                                if(meqdarBlack>meqdarWhite)
                                    payan.setString("Black Nut Win The Match");

                                if(meqdarBlack<meqdarWhite)
                                    payan.setString("White Nut Win The Match");
                                if(meqdarBlack==meqdarWhite)
                                    payan.setString("The Match Is Draw");
                                music.play();
                                pauses=1;
                            }


                        }
                    }

                    if (event.type==sf::Event::MouseButtonPressed)
                    {
                        if(event.mouseButton.button==sf::Mouse::Left)
                        {
                            ezafex=event.mouseButton.x;
                            ezafey=event.mouseButton.y;
                            if(ezafex>975&&ezafex<1185&&ezafey>20&&ezafey<230)
                            {
                                sht++;
                                nahai++;
                            }
                        }
                     }
                }
            }
            window.draw(sprite);
            window.draw(payan);



            sf::Text restart;
            restart.setString("Restart");
            restart.setFont(font);
            restart.setColor(sf::Color::Red);
            restart.setCharacterSize(60);
            restart.setPosition(1000,310);
            if(x1>1000&&x1<1160&&y1>330&&y1<380)
            {
                restart.setStyle(sf::Text::Bold | sf::Text::Underlined );
                restart.setColor(sf::Color::Green);
            }
            window.draw(restart);



            text1.setString("      If You Do Not\n       Have Any Move\n    Click On This Circle");
            text1.setCharacterSize(25);
            text1.setColor(sf::Color::Cyan);
            text1.setPosition(950,70);
            window.draw(text1);


            if(sht%2==1)
            {
                text1.setString("Black Turn");
                text1.setCharacterSize(45);
                text1.setColor(sf::Color::Cyan);
                text1.setPosition(77, 94);
                window.draw(text1);
            }
            if(sht%2==0)
            {
                text2.setString("White Turn");
                text2.setCharacterSize(45);
                text2.setColor(sf::Color::Cyan);
                text2.setPosition(72, 94);
                window.draw(text2);
            }

             m=0,n=0;
            while(m<8)
            {
                while(n<8)
                {
                    if(z[m][n]=='W')
                    {
                        sf::CircleShape shape2(25);
                        a=372+(n)*62.5+4;
                        b=50+(m)*62.5+7;
                        shape2.setPosition(a, b);
                        shape2.setFillColor(sf::Color::White);
                        window.draw(shape2);
                    }
                    if(z[m][n]=='B')
                    {
                        sf::CircleShape shape1(25);
                        a=372+(n)*62.5+4;
                        b=50+(m)*62.5+7;
                        shape1.setPosition(a, b);
                        shape1.setFillColor(sf::Color::Black);
                        window.draw(shape1);
                    }
                    n++;
                }
                n=0;
                m++;
            }


            std::string tostrB=to_str(meqdarBlack);
            sf::Text meqB;
            meqB.setString(tostrB);
            meqB.setFont(font);
            meqB.setCharacterSize(60);
            meqB.setPosition(150,530);
            meqB.setColor(sf::Color::White);
            window.draw(meqB);

            std::string tostrW=to_str(meqdarWhite);
            sf::Text meqW;
            meqW.setString(tostrW);
            meqW.setFont(font);
            meqW.setCharacterSize(60);
            meqW.setPosition(1060,530);
            meqW.setColor(sf::Color::Black);
            window.draw(meqW);



            double i=0;
            while(i<520)
            {
                sf::RectangleShape line1(sf::Vector2f(500, 5));
                line1.setPosition(372, 50+i);
                line1.setFillColor(sf::Color::Red);
                window.draw(line1);
                i+=62.5;
            }
            i=0;
            while(i<520)
            {
                sf::RectangleShape line2(sf::Vector2f(505, 5));
                line2.setPosition(372+i, 50);
                line2.setFillColor(sf::Color::Red);
                line2.rotate(90);
                window.draw(line2);
                i+=62.5;
            }




            window.display();
        }
        sf::Event event2;
        while (window.pollEvent(event2))
            {
                if(event2.type == sf::Event::Closed)
                    window.close();
            }
    }

    return 0;
}
