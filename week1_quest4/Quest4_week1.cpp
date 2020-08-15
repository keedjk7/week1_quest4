#include<stdio.h>
#include<math.h>

struct Bunta {
	int height;
	float weight,BMI;
};
int main() {
	struct Bunta bunta;
	scanf_s("%d%f", &bunta.height, &bunta.weight);
	bunta.BMI = (weight / pow((height / 100), 2));
	printf("%.2f", bunta.BMI);
}