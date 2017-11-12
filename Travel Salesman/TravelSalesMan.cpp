/*
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int shortestDistance = INT_MAX;
int longestDistance = 0;
int shortestNeuron[14][14];
int longestNeuron[14][14];

int main()
{
    srand(time(NULL));
    
    int data[14][14] = {
        { 0, 13, 12, 3, 6, 5, 5, 5, 3, 1, 12, 7, 7, 3 },
        { 13, 0, 6, 12, 6, 6, 10, 14, 11, 9, 10, 4, 11, 9 },
        { 12, 6, 0, 3, 2, 2, 6, 6, 5, 3, 6, 2, 5, 3 },
        { 3, 12, 3, 0, 6, 2, 4, 5, 3, 1, 11, 5, 4, 4 },
        { 6, 6, 2, 6, 0, 2, 7, 8, 7, 4, 6, 1, 6, 5 },
        { 5, 6, 2, 2, 2, 0, 4, 5, 5, 3, 7, 2, 4, 2 },
        { 5, 10, 6, 4, 7, 4, 0, 2, 4, 3, 13, 7, 5, 4 },
        { 5, 14, 6, 5, 8, 5, 2, 0, 5, 3, 14, 8, 5, 3 },
        { 3, 11, 5, 3, 7, 5, 4, 5, 0, 1, 13, 9, 7, 4 },
        { 1, 9, 3, 1, 4, 3, 3, 3, 1, 0, 10, 6, 4, 1 },
        { 12, 10, 6, 11, 6, 7, 13, 14, 13, 6, 0, 8, 12, 11 },
        { 7, 4, 2, 5, 1, 2, 7, 8, 9, 4, 8, 0, 7, 5 },
        { 7, 11, 5, 4, 6, 4, 5, 5, 7, 1, 12, 7, 0, 3 },
        { 3, 9, 3, 4, 5, 2, 4, 3, 4, 2, 11, 5, 3, 0 }
    };
    
    int iterator = 0;
    
    for (int k = 0; k < 1000; k++)
    {
        int randomnum;
        int neuron[14][14]{};
        int temp[14]{};
        int sum = 0;
        
        //creating the random neurons
        for (int i = 0; i < 14; i++)
        {
            randomnum = rand() % 14;
            
            while (temp[randomnum] == 1)
            {
                randomnum = rand() % 14;
            }
            temp[randomnum] = 1;
            neuron[randomnum][i] = 1;
        }
        
        //printing out the neurons activated
        
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 14; j++)
            {
                cout << neuron[j][i] << " ";
            }
            cout << endl;
        }
        
        int initial = 0; //initial position
        //calculating the initial position
        for (int i = 0; i < 14; i++)
        {
            if (neuron[i][0] == 1)
            {
                initial = i;
            }
        }
        
        int next = 0; // next position
        //calculating the distance according to the activated neuron
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 14; j++)
            {
                if (neuron[j][i] == 1)
                {
                    next = j;
                }
            }
            sum += data[initial][next];
            initial = next;
        }
        
        cout << "The total time taken is " << sum << " hours" << endl << endl;
        
        
        if (shortestDistance > sum)
        {
            shortestDistance = sum;
            for (int i = 0; i < 14; i++)
            {
                for (int j = 0; j < 14; j++)
                {
                    shortestNeuron[j][i] = neuron[j][i];
                }
            }
        }
        
        if (longestDistance < sum)
        {
            longestDistance = sum;
            for (int i = 0; i < 14; i++)
            {
                for (int j = 0; j < 14; j++)
                {
                    longestNeuron[j][i] = neuron[j][i];
                }
            }
        }
        
    }
    
    string shortestroute;
    string longestroute;
    cout << "Shortest Neuron: " << endl;
    for (int i = 0; i < 14; i++)
    {
        cout << "\t";
        for (int j = 0; j < 14; j++)
        {
            cout << shortestNeuron[j][i] << " ";
            if (shortestNeuron[j][i] == 1)
            {
                if (j == 0)
                {
                    shortestroute += "-Montgomery-";
                }
                else if (j == 1)
                {
                    shortestroute += "-Juneau-";
                }
                else if (j == 2)
                {
                    shortestroute += "-Phoenix-";
                }
                else if (j == 3)
                {
                    shortestroute += "-Little Rock-";
                }
                else if (j == 4)
                {
                    shortestroute += "-Sacramento-";
                }
                else if (j == 5)
                {
                    shortestroute += "-Denver-";
                }
                else if (j == 6)
                {
                    shortestroute += "-Hartford-";
                }
                else if (j == 7)
                {
                    shortestroute += "-Dover-";
                }
                else if (j == 6)
                         {
                      shortestroute += "-Tallahassee-";
                  }
                  else if (j == 9)
                  {
                      shortestroute += "-Atlanta-";
                  }
                  else if (j == 10)
                  {
                      shortestroute += "-Honolulu-";
                  }
                  else if (j == 11)
                  {
                      shortestroute += "-Boise-";
                  }
                  else if (j == 12)
                  {
                      shortestroute += "-Springfield-";
                  }
                  else if (j == 13)
                  {
                      shortestroute += "-Indianapolis-";
                  }
                  }
                  }
                  cout << endl;
                  }
                  cout << "The shortest distance is " << shortestDistance << endl;
                  cout << "Shortest Path: " << shortestroute << endl << endl;
                  
                  cout << "Longest Neuron: " << endl;
                  for (int i = 0; i < 14; i++)
                  {
                      cout << "\t";
                      for (int j = 0; j < 14; j++)
                      {
                 cout << longestNeuron[j][i] << " ";
               if (longestNeuron[j][i] == 1)
              {
                  if (j == 0)
                  {
                      longestroute += "-Montgomery-";
                  }
                  else if (j == 1)
                  {
                      longestroute += "-Juneau-";
                  }
                  else if (j == 2)
                  {
                      longestroute += "-Phoenix-";
                  }
                  else if (j == 3)
                  {
                      longestroute += "-Little Rock-";
                  }
                  else if (j == 4)
                  {
                      longestroute += "-Sacramento-";
                  }
                  else if (j == 5)
                  {
                      longestroute += "-Denver-";
                  }
                  else if (j == 6)
                  {
                      longestroute += "-Hartford-";
                  }
                  else if (j == 7)
                  {
                      longestroute += "-Dover-";
                  }
                  else if (j == 6)
                {
                    longestroute += "-Tallahassee-";
                }
                else if (j == 9)
                                   {
                   longestroute += "-Atlanta-";
               }
               else if (j == 10)
               {
                   longestroute += "-Honolulu-";
               }
               else if (j == 11)
               {
                   longestroute += "-Boise-";
               }
               else if (j == 12)
               {
                   longestroute += "-Springfield-";
               }
               else if (j == 13)
               {
                   longestroute += "-Indianapolis-";
               }
               }
               }
               cout << endl;
               }
               cout << "The longest distance is " << longestDistance << endl;
                                   cout << "Longest Path: " << longestroute << endl << endl;
                                     
                                     }
*/
 
 #include<iostream>
 #include<string>
 #include<ctime>
 using namespace std;
 
 int shortestDistance = INT_MAX;
 int longestDistance = 0;
 int shortestNeuron[4][4];
 int longestNeuron[4][4];
 
 int main()
 {
	srand(time(NULL));
 
	int data[4][4] = { { 0, 432, 1436, 2509 },
	{ 432, 0, 1779, 2852 },
	{ 1436, 1779, 0, 1317 },
	{ 2509, 2852, 1317, 0 } };
 
 
	int iterator = 0;
 
	for (int k = 0; k <50; k++)
	{
 int randomnum;
 int neuron[4][4]{};
 int temp[4]{};
 int sum = 0;
 
 //creating the random neurons
 for (int i = 0; i < 4; i++)
 {
 randomnum = rand() % 4;
 
 while (temp[randomnum] == 1)
 {
 randomnum = rand() % 4;
 }
 temp[randomnum] = 1;
 neuron[randomnum][i] = 1;
 }
 
 //printing out the neurons activated
 for (int i = 0; i < 4; i++)
 {
 for (int j = 0; j < 4; j++)
 {
 cout << neuron[j][i] << "\t";
 }
 cout << endl;
 }
 
 
 int initial =0 ; //initial position
 //calculating the initial position
 for (int i = 0; i < 4; i++)
 {
 if (neuron[i][0] == 1)
 {
 initial = i;
 }
 }
 
        int next = 0; // next position
 //calculating the distance according to the activated neuron
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (neuron[j][i] == 1)
                {
                    next = j;
                }
            }
            sum += data[initial][next];
            initial = next;
        }
 
        cout << "The distance is " << sum << endl << endl;
 
        if (shortestDistance > sum)
        {
            shortestDistance = sum;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    shortestNeuron[j][i] = neuron[j][i];
                }
            }
        }
 
        if (longestDistance < sum)
    {
        longestDistance = sum;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
     longestNeuron[j][i] = neuron[j][i];
            }
        }
    }
 
	}
 
	string shortestroute;
	string longestroute;
	cout << "Shortest Neuron: " << endl;
	for (int i = 0; i < 4; i++)
	{
        cout << "\t";
        for (int j = 0; j < 4; j++)
        {
            cout << shortestNeuron[j][i] << " ";
            if (shortestNeuron[j][i] == 1)
            {
                if (j == 0)
                {
                    shortestroute+= "-Erie-";
                }
                else if (j== 1)
                {
                    shortestroute += "-New York-";
                }
                else if (j == 2)
                {
                    shortestroute += "-Denver-";
                }
                else if (j == 3)
                {
                    shortestroute += "-Seattle-";
                }
            }
        }
        cout << endl;
    }
        cout << "The shortest distance is " << shortestDistance << endl;
        cout << "Shortest Path: " << shortestroute << endl << endl;
 
	cout << "Longest Neuron: " << endl;
	for (int i = 0; i < 4; i++)
	{
    cout << "\t";
    for (int j = 0; j < 4; j++)
    {
      cout << longestNeuron[j][i] << " ";
     
        if (longestNeuron[j][i] == 1)
        {
            if (j == 0)
            {
                longestroute += "-Erie-";
            }
            else if (j == 1)
            {
                longestroute += "-New York-";
            }
            else if (j == 2)
            {
                longestroute += "-Denver-";
            }
            else if (j == 3)
            {
                longestroute += "-Seattle-";
            }
        }
 
    }
        cout << endl;
    }
        cout <<"The longest distance is " << longestDistance << endl;
        cout << "Longest Path: " << longestroute << endl << endl;
 
 }


