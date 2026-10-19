#include<iostream>
#include<fstream>
#include<iomanip>
#include<climits>

using namespace std;

double area_triangle(int base, double height)
{
    int area_triangle = base*height*(1/2);

    return area_triangle;
}
double  area_polygon(int side_length, int side_number, double distance)
{
    double area_polygon = area_triangle(side_length,distance )* side_number;

    return area_polygon;

}


double perimiter(int side_number, int side_length)
{
    int perimiter = side_number*side_length;

    return perimiter;

}

double cost(int side_number, int side_length, double distance)
{   

    double cost = 3*perimiter(side_number,side_length) + 12*area_polygon(side_number,side_length,distance);


    return cost;
}

int main()
{
    int job_number = 0;
    int side_number = 0;
    int side_length = 0;
    double distance = 0;
    double cost_max = INT_MIN;
    double cost_total = 0;
    double cost_avg = 0;
    ofstream fileWriter;
    ifstream fileReader;

    fileReader.open("jobs.txt");
    fileWriter.open("jobs_output.txt");

    if(fileWriter.is_open()&&fileReader.is_open())
    {
        fileWriter<<setw(10)<<"Job#"<<setw(20)<<"Cost of Paving"<<endl;

        while(fileReader>>job_number>>side_number>>side_length>>distance)
        {
            fileWriter<<setw(10)<<job_number<<setw(20)<<cost(side_number,side_length,distance)<<endl;

            if(cost(side_number,side_length,distance)>cost_max)
            {
                cost_max = cost(side_number,side_length,distance);
            }

            cost_total += cost(side_number,side_length,distance);
            
        }
        cost_avg= cost_total/job_number;

        fileWriter<<setw(30)<<"Maximum cost of all the jobs: "<<cost_max<<endl;
        fileWriter<<setw(25)<<"Total cost of all the Jobs: "<<cost_total<<endl;
        fileWriter<<setw(30)<<"Average cost of all the jobs: "<<cost_avg<<endl;
        
        fileWriter.close();
        fileReader.close();
    }
    else
    {
        cout<<"Trouble Opening files"<<endl;


    }

    return 0;    
    


}