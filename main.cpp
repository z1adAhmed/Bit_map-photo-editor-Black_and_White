// FCI � Programming 1 � 2022 - Assignment 3
// Program Name: CS112-203-2nd�S12-20210118-20210144-20210149-A3-Part1.cpp
// Last Modification Date: 7/7/2022
// Author1 and ID and Group: Hazem Walied Khaled Mohamed / 20210118 / group A
// Author2 and ID and Group: Ziad Ahmed Mahomoud Foad / 20210144 / group A
// Author3 and ID and Group: Ziad Tarek Sayed Ali El-Masry / 20210149 / group A
// Teaching Assistant: Eng. Afaf abdelmonem
// Purpose: processing on gray scale images


#include<bits/stdc++.h>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char part1[128][128]= {0};
unsigned char part2[128][128]= {0};
unsigned char part3[128][128]= {0};
unsigned char part4[128][128]= {0};
char choice;
void display_menu();
void load_image();
void load_image_tomerge();
void save_image();
void save_merged();
void filter_1();
void filter_2();
void filter_3();
void filter_4();
void filter_5();
void filter_6();
void filter_7();
void filter_8();
void filter_9();
void filter_a();
void filter_b();
void filter_c();

int main()
{
    cout<<"!! Welcome to GSIP !!"<<endl<<endl;
    while(true)
    {
        display_menu();
        if (choice=='1')
        {
            load_image();
            filter_1();
            save_image();
        }
        else if (choice=='2')
        {
            load_image();
            filter_2();
            save_image();
        }
        else if (choice=='3')
        {
            load_image();
            load_image_tomerge();
            filter_3();
            save_merged();
        }
        else if (choice=='4')
        {
            load_image();
            filter_4();
            save_image();
        }
        else if (choice=='5')
        {
            load_image();
            filter_5();
            save_image();
        }
        else if (choice=='6')
        {
            load_image();
            filter_6();
            save_image();
        }
        else if (choice=='7')
        {
            load_image();
            filter_7();
            save_image();
        }
        else if (choice=='8')
        {
            load_image();
            filter_8();
            save_image();
        }
        else if (choice=='9')
        {
            load_image();
            filter_9();
            save_image();
        }
        else if (choice=='a')
        {
            load_image();
            filter_a();
            save_image();
        }
        else if (choice=='b')
        {
            load_image();
            filter_b();
            save_image();
        }
        else if (choice=='c')
        {
            load_image();
            filter_c();
            save_image();
        }
        else if (choice=='0')
        {
            exit(0);
        }
    }
}

void load_image()
{
    char image_name[150];
    cout<<"Please enter the name of the image file: ";
    cin>> image_name;
    strcat(image_name,".bmp");
    readGSBMP(image_name,image);
}

void load_image_tomerge()
{
    char image_name2[150];
    cout<<"Please enter the name of the image file to merge with: ";
    cin>> image_name2;
    strcat(image_name2,".bmp");
    readGSBMP(image_name2,image2);
}

void save_image()
{
    char newimage_name[150];
    cout<<"Please enter the name of the new image to be saved: ";
    cin>>newimage_name;
    strcat(newimage_name,".bmp");
    writeGSBMP(newimage_name,image);
}

void save_merged()
{
    char newimage_name[150];
    cout<<"Please enter the name of the new image to be saved: ";
    cin>>newimage_name;
    strcat(newimage_name,".bmp");
    writeGSBMP(newimage_name,image3);
}

void filter_1()
{
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > 127)
                image [i][j] = 255;
            else
                image [i][j] = 0;
        }
    }
}
void filter_2()
{
    for(int i= 0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}
void filter_3()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            image3[i][j]=((image[i][j]+image2[i][j])/4);
        }
    }
}
void filter_4()
{
    int row1 = 0;
    int row2 = (SIZE - 1);
    unsigned char update [SIZE];
    bool test = true;
    while (test == true)
    {

        for (int i = 0; i < SIZE; i++)
        {
            update [i] = image [row1][i];
        }
        for (int k = 0; k < SIZE; k++)
        {
            image [row1][k] = image [row2][k];
        }
        for (int j = 0; j < SIZE; j++)
        {
            image [row2][j] = update [j];
        }
        row1 = row1 + 1;
        row2 = row2 - 1;
        if (row1 == 128)
            test = false;
    }
}
void filter_5()
{
    string degree;
    cout<<"Please enter the degree to rotate with (90,180,270) --> ";
    cin>> degree;
    if(degree == "90")
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=i; j<SIZE; j++)
            {
                swap(image[i][j],image[j][i]);
            }
        }
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE/2; j++)
            {
                swap(image[i][j],image[i][255-j]);
            }
        }
    }
    else if (degree == "180")
    {
        for(int i=0; i<SIZE/2; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                swap(image[i][j],image[255-i][255-j]);
            }
        }
    }
    else if (degree == "270")
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=i; j<SIZE; j++)
            {
                swap(image[i][j],image[j][i]);
            }
        }
        for(int i=0; i<SIZE/2; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                swap(image[i][j],image[255-i][255-j]);
            }
        }
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE/2; j++)
            {
                swap(image[i][j],image[i][255-j]);
            }
        }
    }
}
void filter_6()
{
   long avg;
int desscion;
cout<<"to darken enter 1 to lighten enter 2 ";
cin>>desscion;

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

                    if(desscion==1){
                        avg=(image[i][j]/2);
                         image[i][j]-=avg;
                    }
                    else{
                        avg=(255-image[i][j])/2;
                        image[i][j]+=avg;
                    }

       }
    }
}
void filter_7()
{
    unsigned char photo [SIZE][SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > 127)
                image [i][j] = 255;
            else
                image [i][j] = 0;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            photo[i][j] = (image[i-1][j]+image[i+1][j]+image[i][j+1]+image[i][j-1])-(8 * image[i][j]);
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image [i][j] = photo [i][j];
        }
    }
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image [i][j] = 255 - image [i][j] ;
        }
    }
}
void filter_8()
{
    for (int i=0;i<SIZE/2;i++)
    {
        for (int j=0;j<SIZE/2;j++)
        {
            part1[i][j]=image[i][j];
        }
    }
    for (int i=0;i<SIZE/2;i++)
    {
        for (int j=SIZE/2;j<SIZE;j++)
        {
            part2[i][j-128]=image[i][j];
        }
    }
    for (int i=SIZE/2;i<SIZE;i++)
    {
        for (int j=0;j<SIZE/2;j++)
        {
            part3[i-128][j]=image[i][j];
        }
    }
    for (int i=SIZE/2;i<SIZE;i++)
    {
        for (int j=SIZE/2;j<SIZE;j++)
        {
            part4[i-128][j-128]=image[i][j];
        }
    }
    int chosen;
    cout<<"Enter the part you want to enlarge (1)(2)(3)(4): ";
    cin>>chosen;
    if (chosen==1)
    {
        for(int i=0,k=0; i<SIZE; i+=2,k++)
        {
            for(int j=0,l=0; j<SIZE; j+=2,l++)
            {
                image[i][j]=part1[k][l];
                image[i+1][j]=part1[k][l];
                image[i][j+1]=part1[k][l];
                image[i+1][j+1]=part1[k][l];
            }
        }
    }
    else if (chosen == 2)
    {
        for(int i=0,k=0; i<SIZE; i+=2,k++)
        {
            for(int j=0,l=0; j<SIZE; j+=2,l++)
            {
                image[i][j]=part2[k][l];
                image[i+1][j]=part2[k][l];
                image[i][j+1]=part2[k][l];
                image[i+1][j+1]=part2[k][l];
            }
        }
    }
    else if (chosen == 3)
    {
        for(int i=0,k=0; i<SIZE; i+=2,k++)
        {
            for(int j=0,l=0; j<SIZE; j+=2,l++)
            {
                image[i][j]=part3[k][l];
                image[i+1][j]=part3[k][l];
                image[i][j+1]=part3[k][l];
                image[i+1][j+1]=part3[k][l];
            }
        }
    }
    else if (chosen == 4)
    {
        for(int i=0,k=0; i<SIZE; i+=2,k++)
        {
            for(int j=0,l=0; j<SIZE; j+=2,l++)
            {
                image[i][j]=part4[k][l];
                image[i+1][j]=part4[k][l];
                image[i][j+1]=part4[k][l];
                image[i+1][j+1]=part4[k][l];
            }
        }
    }

}
void filter_9()
{
    int desscion;
    cout<<"***1-shrink half***\n***2-shrink third***\n***3-shrink quarter***\n";
    cin>>desscion;
    if (desscion==1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i/2][j/2]=image[i][j];
                image[i][j]=255;
            }
        }
    }
    else if (desscion==2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i/3][j/3]=image[i][j];
                image[i][j]=255;
            }
        }
    }
    if (desscion==3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i/4][j/4]=image[i][j];
                image[i][j]=255;
            }
        }
    }
}
void filter_a()
{
    int counter1 = 0;
    int counter2 = (SIZE - 1);
    bool test = true;
    int choice;
    cout << "Please choose the 1/2 which is wanted to be mirrored:" << endl << "1-For the upper half" << endl;
    cout << "2-For the lower half" << endl;
    cout << "3-For the right half" << endl;
    cout << "4-For the left half" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        while (test == true)
        {
            for(int i = 0; i < SIZE; i++)
            {
                image [counter2][i] = image [counter1][i];
            }
            counter1 = counter1 + 1;
            counter2 = counter2 - 1;
            if (counter1 == 128)
                test = false;
        }
    }
    if (choice == 2)
    {
        while (test == true)
        {
            for(int i = 0; i < SIZE; i++)
            {
                image [counter1][i] = image [counter2][i];
            }
            counter1 = counter1 + 1;
            counter2 = counter2 - 1;
            if (counter1 == 128)
                test = false;
        }
    }
    if (choice == 3)
    {
        while (test == true)
        {
            for(int i = 0; i < SIZE; i++)
            {
                image [i][counter1] = image [i][counter2];
            }
            counter1 = counter1 + 1;
            counter2 = counter2 - 1;
            if (counter1 == 128)
                test = false;
        }
    }
}
void filter_b()
{
    unsigned char sorted1[128][128];
    unsigned char sorted2[128][128];
    unsigned char sorted3[128][128];
    unsigned char sorted4[128][128];
    for(int i=0 ; i<128; i++)
    {
        for(int j =0; j<128; j++)
        {
            part1[i][j]=image[i][j];
        }
    }
    for(int i=0 ; i<128; i++)
    {
        for(int j =0; j<128; j++)
        {
            part2[i][j]=image[i][128+j];
        }
    }
    for(int i=0 ; i<128; i++)
    {
        for(int j =0; j<128; j++)
        {
            part3[i][j]=image[128+i][j];
        }
    }
    for(int i=0 ; i<128; i++)
    {
        for(int j =0; j<128; j++)
        {
            part4[i][j]=image[128+i][128+j];
        }
    }

    string order;
    cout<<"Enter the order to shuffle WITHOUT SPACES: ";
    cin.ignore();
    getline(cin,order);
    //////////////////////////////////////////////////////////////
    if (order[0]=='1' && order[1]=='2' && order[2]=='3' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part4[i][j];
            }
        }
    }
    else if (order[0]=='1' && order[1]=='2' && order[2]=='4' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part3[i][j];
            }
        }
    }
    else if (order[0]=='1' && order[1]=='3' && order[2]=='2' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part4[i][j];
            }
        }
    }
    else if (order[0]=='1' && order[1]=='3' && order[2]=='4' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part2[i][j];
            }
        }
    }
    else if (order[0]=='1' && order[1]=='4' && order[2]=='2' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part3[i][j];
            }
        }
    }
    else if (order[0]=='1' && order[1]=='4' && order[2]=='3' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part2[i][j];
            }
        }
    }
    else if (order[0]=='2' && order[1]=='1' && order[2]=='3' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part4[i][j];
            }
        }
    }
    else if (order[0]=='2' && order[1]=='1' && order[2]=='4' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part3[i][j];
            }
        }
    }
    else if (order[0]=='2' && order[1]=='3' && order[2]=='1' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part4[i][j];
            }
        }
    }
    else if (order[0]=='2' && order[1]=='3' && order[2]=='4' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part1[i][j];
            }
        }
    }
    else if (order[0]=='2' && order[1]=='4' && order[2]=='3' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part1[i][j];
            }
        }
    }
    else if (order[0]=='2' && order[1]=='4' && order[2]=='1' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part3[i][j];
            }
        }
    }
    else if (order[0]=='1' && order[1]=='2' && order[2]=='4' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part3[i][j];
            }
        }
    }
    else if (order[0]=='3' && order[1]=='1' && order[2]=='2' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part4[i][j];
            }
        }
    }
    else if (order[0]=='3' && order[1]=='1' && order[2]=='4' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part2[i][j];
            }
        }
    }
    else if (order[0]=='3' && order[1]=='2' && order[2]=='1' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part4[i][j];
            }
        }
    }
    else if (order[0]=='3' && order[1]=='2' && order[2]=='4' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part1[i][j];
            }
        }
    }
    else if (order[0]=='3' && order[1]=='4' && order[2]=='1' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part2[i][j];
            }
        }
    }
    else if (order[0]=='3' && order[1]=='4' && order[2]=='2' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part1[i][j];
            }
        }
    }
    else if (order[0]=='4' && order[1]=='1' && order[2]=='3' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part2[i][j];
            }
        }
    }
    else if (order[0]=='4' && order[1]=='1' && order[2]=='2' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part3[i][j];
            }
        }
    }
    else if (order[0]=='4' && order[1]=='2' && order[2]=='1' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part3[i][j];
            }
        }
    }
    else if (order[0]=='4' && order[1]=='2' && order[2]=='3' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part1[i][j];
            }
        }
    }
    else if (order[0]=='4' && order[1]=='3' && order[2]=='1' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part1[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part2[i][j];
            }
        }
    }
    else if (order[0]=='4' && order[1]=='3' && order[2]=='2' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted1[i][j] = part4[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted2[i][j] = part3[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted3[i][j] = part2[i][j];
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                sorted4[i][j] = part1[i][j];
            }
        }
    }
    else
    {
        cout<<"invalid order"<<endl;
    }
    ////////////////////////////////----saving the image----/////////////////////////////////
    for(int i=0; i<SIZE/2; i++)
    {
        for(int j=0; j<SIZE/2; j++)
        {
            image[i][j] = sorted1[i][j];
        }
    }
    for(int i=0; i<SIZE/2; i++)
    {
        for(int j=SIZE/2; j<SIZE; j++)
        {
            image[i][j] = sorted2[i][j-128];
        }
    }
    for(int i=SIZE/2; i<SIZE; i++)
    {
        for(int j=0; j<SIZE/2; j++)
        {
            image[i][j] = sorted3[i-128][j];
        }
    }
    for(int i=SIZE/2; i<SIZE; i++)
    {
        for(int j=SIZE/2; j<SIZE; j++)
        {
            image[i][j] = sorted4[i-128][j-128];
        }
    }
}
void filter_c()
{
      for(int l = 0; l < 15; l++){
        for(int i = 0; i<SIZE; i++){
            for(int j = 2; j<SIZE; j++){
                image2[i][j-1] = (image[i][j]+image[i][j-2])/2;
            }
            for(int j = 0; j < SIZE; j++){
                if(i == 0){
                    break;
                }
                image2[i-1][j] = (image[i-2][j]+image[i][j])/2;
            }
        }
        for(int i = 0; i<SIZE; i++){
            for(int j = 0; j<SIZE; j++){
                image[i][j] = image2[i][j];
            }
        }
    }
}

void display_menu()
{
    cout<<endl<<"1- Black & White Filter."<<endl;
    cout<<"2- Invert Image."<<endl;
    cout<<"3- Merge Images."<<endl;
    cout<<"4- Flip Image."<<endl;
    cout<<"5- Rotate Image."<<endl;
    cout<<"6- Darken and Lighten Image."<<endl;
    cout<<"7- Detect Image Edges."<<endl;
    cout<<"8- Enlarge Image."<<endl;
    cout<<"9- Shrink Image."<<endl;
    cout<<"a- Mirror Image."<<endl;
    cout<<"b- Shuffle Image."<<endl;
    cout<<"c- Blur Image."<<endl;
    cout<<"0- EXIT."<<endl<<endl;
    cout<<"Please enter the filter you want to apply otherwise enter {0} to exit: "<<endl;
    cin>>choice;

}

