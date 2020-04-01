#include <math.h>

//Calculates the average of a data set
double averager(float data[], int size)
{
    int i;
    float answer = 0.0;

    for (i = 0; i < size; i++)
    {
        answer += data[i];
    }

    answer /= size;

    return answer;
}

//Calculates standard deviation of a data set.
double sDeviator(float data[], int size)
{

    int i;
    float answer = 0.0;
    float average;
    average = averager(data, size);

    for (i = 0; i < size; i++)
    {
        answer += ((data[i] - average) * (data[i] - average));
    }

    answer /= size;
    answer = sqrt(answer);

    return answer;
}

//Calculates the zscores of a data set from its average and deviation.
void zScorer(float data[], int size, float zScores[])
{
    int i;
    float average;
    float deviation;
    float answers = 0.0;

    deviation = sDeviator(data, size);
    average = averager(data, size);

    for (i = 0; i < size; i++)
    {
        answers = (data[i] - average) / deviation;
        zScores[i] = answers;
    }
}