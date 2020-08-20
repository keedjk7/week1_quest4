#include<stdio.h>
#include<math.h>

double T1, T2, T3, CR, S1, S2;

struct Bunta {
	float weight_before,weight_after,BMI_before,BMI_after,height;
};

struct field {
	double sumT, sumS, sumC;
};


double triangle() {
	double sumT;
	T3 = sqrt(((T1 * T1) + (T2 * T2)));
	sumT = T1 + T2 + T3;
	return sumT;
}

double square() {
	double sumS;
	sumS = S1 + S1 + S2 + S2;
	return sumS;
}

double circle() {
	double sumC;
	sumC = 2 * 3.14 * CR;
	return sumC;
}

float calculation(float height,float weight,float sum) {
	weight -= ((sum * 1000) / 100) * 0.02;
	return weight;
}

float SUM(char field_type, float sumT, float sumS, float sumC,float S) {
	if (field_type == 'T') {
		S += sumT;
	}
	else if (field_type == 'S') {
		S += sumS;
	}
	else if (field_type == 'C') {
		S += sumC;
	}
	return S;
}
float BMI(float weight,float height) {
	float BMI;
	BMI = weight / float((height / 100)*(height / 100));
	return BMI;
}

int main() {
	struct Bunta bunta;
	struct field field;
	printf("Bunta Height Before Exercise : ");
	scanf_s("%f", &bunta.height);
	printf("Bunta Weight Before Exercise : ");
	scanf_s("%f", &bunta.weight_before);
	bunta.BMI_before=BMI(bunta.weight_before,bunta.height);

	
	if (bunta.BMI_before < 23) {
		printf("Now you're slim, no exercise needed.\nBMI = %.2f", bunta.BMI_before);
	}
	else {		
		int day;
		char field_type;
		double sum=0;
		//INPUT
		printf("Input Day for Exercise : ");
		scanf_s("%d", &day);
		printf("Height of Triangle Field : ");
		scanf_s("%lf", &T1);
		printf("Base of Triangle Field : ");
		scanf_s("%lf", &T2);
		printf("Height of Square : ");
		scanf_s("%lf", &S1);
		printf("Base of Square : ");
		scanf_s("%lf", &S2);
		printf("Radius of Circle : ");
		scanf_s("%lf", &CR);

		field.sumT = triangle();
		field.sumS = square();
		field.sumC = circle();
		for (int i = 0; i < day; i++) {
			printf("Day %d - Field Type : ", i + 1);
			scanf_s("%c ", &field_type);
			sum = SUM(field_type, field.sumT, field.sumS, field.sumC, sum);
		}
		bunta.weight_after = calculation(bunta.height, bunta.weight_before,sum );
		bunta.BMI_after = BMI(bunta.weight_after, bunta.height);
		//OUTPUT
		printf("Now you're fat ,need to exercise.\n");
		printf("BMI Before Exercise = %.2f\n\n", bunta.BMI_before);
		if (bunta.BMI_after >= 23) {
				printf("Now,you're still fat.\n");
		}
		else {
			printf("Now,you are thin.\n");
		}
		printf("Weight After Exercise = %.2f Kg.\n", bunta.weight_after);
		printf("BMI After Exercise = %.2f\n", bunta.BMI_after);

	}
	return 0;
}