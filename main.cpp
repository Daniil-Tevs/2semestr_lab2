#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> // для функций из std::chrono

class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

double key(double &d) {
    return d;
}

void QUICKSORT(int a, int b, std::vector<double> &x)
{
    if(a>=b)
        return;
    int m=a+rand()%(b-a+1);
    double k=key(x[m]);
    int l=a-1;
    int r=b+1;
    while(true)
    {
        do{l++;}while(key(x[l])<k);
        do{r--;}while(key(x[r])>k);
        if(l>=r)
            break;
        std::swap(x[l],x[r]);
    }
    r=l;l=r-1;
    QUICKSORT(a,l,x);
    QUICKSORT(r,b,x);
}


int main() {
    std::ofstream out("../output.txt");
    int d=1;
    int N,k,a,b;
    std::cin>>N;
    std::vector<double> mass;
    for(int i=0;i<N;i++)
        mass.push_back(rand()%1000);
    for(int i=0;i<N;i++)
        out<<mass[i]<<" ";
    out<<"\n";
    QUICKSORT(0,mass.size()-1,mass);
    for(int i=0;i<N;i++)
        out<<mass[i]<<" ";
    return 0;
}
