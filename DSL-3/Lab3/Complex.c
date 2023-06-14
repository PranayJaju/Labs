#include<stdio.h>
#include<math.h>
typedef struct
{
	double real;
	double img;
}Complex;

Complex add(Complex* c1, Complex* c2)
{
	Complex addRes;
	Complex* paR=&addRes;
	paR->real=c1->real+c2->real;
	paR->img=c1->img+c2->img;
	return addRes;
}

Complex subtract(Complex* c1, Complex* c2)
{
	Complex subRes;
	Complex* psR=&subRes;
	psR->real=c1->real-c2->real;
	psR->img=c1->img-c2->img;
	return subRes;
}

Complex multiply(Complex* c1, Complex* c2)
{
	Complex mulRes;
	Complex* pmR=&mulRes;
	pmR->real=(c1->real*c2->real)-(c1->img*c2->img);
	pmR->img=(c1->real*c2->img)+(c2->real*c1->img);
	return mulRes;
}

void main()
{
	double a,b,x,y;
	printf("Enter Complex Number 1.\n");
    scanf("%lf %lf", &a, &b);
   	printf("Enter Complex Number 2.\n");
    scanf("%lf %lf", &x, &y);

    Complex c1; Complex* pC1=&c1;
    pC1->real=a; pC1->img=b;

    Complex c2; Complex* pC2=&c2;
    pC2->real=x; pC2->img=y;

    Complex addRes=add(pC1, pC2);
    if(addRes.img<0.0)
        printf("Addition: %.2lf-i%.2lf\n", addRes.real, fabs(addRes.img));
    else
        printf("Addition: %.2lf+i%.2lf\n", addRes.real, addRes.img);

    Complex subRes=subtract(pC1, pC2);
    if(subRes.img<0.0)
        printf("Subtraction: %.2lf-i%.2lf\n", subRes.real, fabs(subRes.img));
    else
        printf("Subtraction: %.2lf+i%.2lf\n", subRes.real, subRes.img);
        
    Complex mulRes=multiply(pC1, pC2);
    if(mulRes.img<0.0)
        printf("Multiplication: %.2lf-i%.2lf\n", mulRes.real, fabs(mulRes.img));
    else
        printf("Multiplication: %.2lf+i%.2lf\n", mulRes.real, mulRes.img);        
}