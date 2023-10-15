#include <stdio.h>
#include <stdlib.h>
struct term
{
	int coefficient;
	int exponent;
};
struct Polynomial
{
	int numberOfTerms;
	struct term *terms;
};
void getPolynomial(struct Polynomial *polynomial)
{
	int i;
	printf("Enter the coefficient and the corresponding term in the decreasing order of the exponents \n");
        for(i = 0; i < polynomial->numberOfTerms; i++)
        { 
                printf("Enter the term %d in the format (coefficient, exponent): ", i + 1);
                scanf("%d %d", &polynomial->terms[i].coefficient, &polynomial->terms[i].exponent);
        }

}
void addPolynomial(struct Polynomial p1, struct Polynomial p2, struct Polynomial *sum)
{
	int i = 0, j = 0, count = 0;
        while(i < p1.numberOfTerms && j < p2.numberOfTerms)
        {
                if(p1.terms[i].exponent == p2.terms[j].exponent)
                {
			sum->terms[count].coefficient = p1.terms[i].coefficient + p2.terms[j].coefficient;
                        sum->terms[count].exponent = p1.terms[i].exponent;
			++i; 
                        ++j;
                        ++count;
                }
                else if(p1.terms[i].exponent > p2.terms[j].exponent)
                {
			sum->terms[count].coefficient = p1.terms[i].coefficient;
			sum->terms[count].exponent = p1.terms[i].exponent;
                        ++i;
                        ++count;
                }
                else
                {
			sum->terms[count].coefficient = p2.terms[j].coefficient;
                        sum->terms[count].exponent = p2.terms[j].exponent;
                        ++j;
                        ++count;
                }
        }
        for(; i < p1.numberOfTerms; i++)
                sum->terms[count++].coefficient = p1.terms[i].coefficient;
        for(; j < p2.numberOfTerms; j++)
                sum->terms[count++].exponent = p2.terms[j].exponent;
}
int getSize(struct Polynomial p1, struct Polynomial p2)
{
	int i = 0, j = 0, size = 0;
        while(i < p1.numberOfTerms && j < p2.numberOfTerms)
        {
                if(p1.terms[i].exponent == p2.terms[j].exponent)
                {
                        ++i;
                        ++j;    
                        ++size;
                }
                else if(p1.terms[i].exponent > p2.terms[j].exponent)
                {
                        ++i;
                        ++size;
                }
                else
                {
                        ++j;
                        ++size;
                }
        }
        for(; i < p1.numberOfTerms; i++)
                size++;
        for(; j < p2.numberOfTerms; j++)
                size++;
	return size;
}
void printPolynomial(struct Polynomial *p)
{
	int i;
	for(i = 0; i < p->numberOfTerms - 1 && p->terms[i].coefficient != 0; i++)
	{
		if(p->terms[i].coefficient < 0)
			printf("- %dx^%d ", p->terms[i].coefficient, p->terms[i].exponent);
		else
			printf("+ %dx^%d ", p->terms[i].coefficient, p->terms[i].exponent);
	}
		printf("+ %d\n ", p->terms[i].coefficient);
}
int main()
{
	int term1, term2, sumSize;
	printf("Enter the number of terms in the first polynomial : ");
	scanf("%d", &term1);
	struct Polynomial polynomial1;
	polynomial1.numberOfTerms = term1;
	polynomial1.terms = (struct term* )malloc(term1 * sizeof(struct term));
	getPolynomial(&polynomial1);
	printPolynomial(&polynomial1);
	printf("Enter the number of terms in the second polynomial : ");
	scanf("%d", &term2);
	struct Polynomial polynomial2;
        polynomial2.numberOfTerms = term2;
        polynomial2.terms = (struct term* )malloc(term2 * sizeof(struct term));
        getPolynomial(&polynomial2);
	printPolynomial(&polynomial2);
	sumSize = getSize(polynomial1, polynomial2);
	struct Polynomial sum ;
	sum.numberOfTerms = sumSize;
	sum.terms = (struct term *)malloc(sumSize * sizeof(struct term));
	addPolynomial(polynomial1, polynomial2, &sum);
	printPolynomial(&sum);
}	
