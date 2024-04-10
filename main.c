#include <stdio.h>

int getMeasurements(float *pres, float *temp, float *hum)
{
	FILE *fptr;
	float p, t, h;
	int n, res;

	fptr = popen("dracal-usb-get -i a", "r");
	if (!fptr) {
		perror("popen");
		return -1;
	}

	n = fscanf(fptr, "%f, %f, %f", &p, &t, &h);
	res = pclose(fptr);

	if (res==-1) { return -2; }
	if (n<2) { return -3; }

	if (pres) { *pres = p; }
	if (temp) { *temp = t; }
	if (hum) { *hum = h; }

	return 0;
}

int main(void)
{
	float pressure, temperature, humidity;
	int res;

	res = getMeasurements(&pressure, &temperature, &humidity);
	if (res<0) {
		return res;
	}

  printf("Pressure. (kPa): %.2f\n", pressure);
  printf("Temperature (C): %.2f\n", temperature);
  printf("RH......... (%%): %.2f\n", humidity);
  printf("Temperature (F): %.2f\n", temperature * 9 / 5 + 32);

	return 0;
}
