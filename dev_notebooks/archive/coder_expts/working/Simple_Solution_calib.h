#include <math.h>


static double Simple_Solution_dparam_g(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = n1*n2/(n1 + n2 + n3);
        break;
    case 3:
        result = -T*n1*n2/(n1 + n2 + n3);
        break;
    case 4:
        result = P*n1*n2/(n1 + n2 + n3);
        break;
    case 5:
        result = n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 6:
        result = -T*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 7:
        result = P*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 8:
        result = n1*n3/(n1 + n2 + n3);
        break;
    case 9:
        result = -T*n1*n3/(n1 + n2 + n3);
        break;
    case 10:
        result = P*n1*n3/(n1 + n2 + n3);
        break;
    case 11:
        result = n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 12:
        result = -T*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 13:
        result = P*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 14:
        result = n2*n3/(n1 + n2 + n3);
        break;
    case 15:
        result = -T*n2*n3/(n1 + n2 + n3);
        break;
    case 16:
        result = P*n2*n3/(n1 + n2 + n3);
        break;
    case 17:
        result = n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 18:
        result = -T*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 19:
        result = P*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 20:
        result = n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 21:
        result = -T*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 22:
        result = P*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_dgdt(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = -n1*n2/(n1 + n2 + n3);
        break;
    case 4:
        result = 0;
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = -n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 7:
        result = 0;
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = -n1*n3/(n1 + n2 + n3);
        break;
    case 10:
        result = 0;
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = -n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 13:
        result = 0;
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = -n2*n3/(n1 + n2 + n3);
        break;
    case 16:
        result = 0;
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = -n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 19:
        result = 0;
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = -n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 22:
        result = 0;
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_dgdp(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    case 4:
        result = n1*n2/(n1 + n2 + n3);
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = 0;
        break;
    case 7:
        result = n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = 0;
        break;
    case 10:
        result = n1*n3/(n1 + n2 + n3);
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = 0;
        break;
    case 13:
        result = n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = 0;
        break;
    case 16:
        result = n2*n3/(n1 + n2 + n3);
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = 0;
        break;
    case 19:
        result = n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = 0;
        break;
    case 22:
        result = n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_d2gdt2(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    case 4:
        result = 0;
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = 0;
        break;
    case 7:
        result = 0;
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = 0;
        break;
    case 10:
        result = 0;
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = 0;
        break;
    case 13:
        result = 0;
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = 0;
        break;
    case 16:
        result = 0;
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = 0;
        break;
    case 19:
        result = 0;
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = 0;
        break;
    case 22:
        result = 0;
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_d2gdtdp(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    case 4:
        result = 0;
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = 0;
        break;
    case 7:
        result = 0;
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = 0;
        break;
    case 10:
        result = 0;
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = 0;
        break;
    case 13:
        result = 0;
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = 0;
        break;
    case 16:
        result = 0;
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = 0;
        break;
    case 19:
        result = 0;
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = 0;
        break;
    case 22:
        result = 0;
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_d2gdp2(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    case 4:
        result = 0;
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = 0;
        break;
    case 7:
        result = 0;
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = 0;
        break;
    case 10:
        result = 0;
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = 0;
        break;
    case 13:
        result = 0;
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = 0;
        break;
    case 16:
        result = 0;
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = 0;
        break;
    case 19:
        result = 0;
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = 0;
        break;
    case 22:
        result = 0;
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_d3gdt3(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    case 4:
        result = 0;
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = 0;
        break;
    case 7:
        result = 0;
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = 0;
        break;
    case 10:
        result = 0;
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = 0;
        break;
    case 13:
        result = 0;
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = 0;
        break;
    case 16:
        result = 0;
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = 0;
        break;
    case 19:
        result = 0;
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = 0;
        break;
    case 22:
        result = 0;
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_d3gdt2dp(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    case 4:
        result = 0;
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = 0;
        break;
    case 7:
        result = 0;
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = 0;
        break;
    case 10:
        result = 0;
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = 0;
        break;
    case 13:
        result = 0;
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = 0;
        break;
    case 16:
        result = 0;
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = 0;
        break;
    case 19:
        result = 0;
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = 0;
        break;
    case 22:
        result = 0;
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_d3gdtdp2(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    case 4:
        result = 0;
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = 0;
        break;
    case 7:
        result = 0;
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = 0;
        break;
    case 10:
        result = 0;
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = 0;
        break;
    case 13:
        result = 0;
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = 0;
        break;
    case 16:
        result = 0;
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = 0;
        break;
    case 19:
        result = 0;
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = 0;
        break;
    case 22:
        result = 0;
        break;

    default:
        break;
    }
        return result;
}

static double Simple_Solution_dparam_d3gdp3(double T, double P, double n[3], int index) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    double result = 0.0;
    switch (index) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 0;
        break;
    case 3:
        result = 0;
        break;
    case 4:
        result = 0;
        break;
    case 5:
        result = 0;
        break;
    case 6:
        result = 0;
        break;
    case 7:
        result = 0;
        break;
    case 8:
        result = 0;
        break;
    case 9:
        result = 0;
        break;
    case 10:
        result = 0;
        break;
    case 11:
        result = 0;
        break;
    case 12:
        result = 0;
        break;
    case 13:
        result = 0;
        break;
    case 14:
        result = 0;
        break;
    case 15:
        result = 0;
        break;
    case 16:
        result = 0;
        break;
    case 17:
        result = 0;
        break;
    case 18:
        result = 0;
        break;
    case 19:
        result = 0;
        break;
    case 20:
        result = 0;
        break;
    case 21:
        result = 0;
        break;
    case 22:
        result = 0;
        break;

    default:
        break;
    }
        return result;
}
static void Simple_Solution_dparam_dgdn(double T, double P, double n[3], int index, double result[3]) {
    double n1 = n[0];
    double n2 = n[1];
    double n3 = n[2];
    switch (index) {
    case 0:
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
        break;
    case 1:
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
        break;
    case 2:
        result[0] = -n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) + n2/(n1 + n2 + n3);
        result[1] = -n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) + n1/(n1 + n2 + n3);
        result[2] = -n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 3:
        result[0] = T*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n2/(n1 + n2 + n3);
        result[1] = T*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n1/(n1 + n2 + n3);
        result[2] = T*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 4:
        result[0] = -P*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n2/(n1 + n2 + n3);
        result[1] = -P*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n1/(n1 + n2 + n3);
        result[2] = -P*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 5:
        result[0] = -2*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) + n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -2*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) + n1*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -2*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 6:
        result[0] = 2*T*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - T*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = 2*T*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + T*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n1*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = 2*T*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 7:
        result[0] = -2*P*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + P*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -2*P*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - P*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n1*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -2*P*n1*n2*(n1 - n2)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 8:
        result[0] = -n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + n3/(n1 + n2 + n3);
        result[1] = -n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + n1/(n1 + n2 + n3);
        break;
    case 9:
        result[0] = T*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n3/(n1 + n2 + n3);
        result[1] = T*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = T*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n1/(n1 + n2 + n3);
        break;
    case 10:
        result[0] = -P*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n3/(n1 + n2 + n3);
        result[1] = -P*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -P*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n1/(n1 + n2 + n3);
        break;
    case 11:
        result[0] = -2*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -2*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -2*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + n1*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 12:
        result[0] = 2*T*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - T*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = 2*T*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = 2*T*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + T*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n1*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 13:
        result[0] = -2*P*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + P*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -2*P*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -2*P*n1*n3*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - P*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n1*(n1 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 14:
        result[0] = -n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + n3/(n1 + n2 + n3);
        result[2] = -n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + n2/(n1 + n2 + n3);
        break;
    case 15:
        result[0] = T*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = T*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n3/(n1 + n2 + n3);
        result[2] = T*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n2/(n1 + n2 + n3);
        break;
    case 16:
        result[0] = -P*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -P*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n3/(n1 + n2 + n3);
        result[2] = -P*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n2/(n1 + n2 + n3);
        break;
    case 17:
        result[0] = -2*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -2*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -2*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + n2*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 18:
        result[0] = 2*T*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = 2*T*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - T*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = 2*T*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + T*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) - T*n2*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 19:
        result[0] = -2*P*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -2*P*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + P*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -2*P*n2*n3*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - P*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)) + P*n2*(n2 - n3)/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 20:
        result[0] = -2*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -2*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -2*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 21:
        result[0] = 2*T*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - T*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = 2*T*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - T*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = 2*T*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) - T*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    case 22:
        result[0] = -2*P*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + P*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[1] = -2*P*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + P*n1*n3/((n1 + n2 + n3)*(n1 + n2 + n3));
        result[2] = -2*P*n1*n2*n3/((n1 + n2 + n3)*(n1 + n2 + n3)*(n1 + n2 + n3)) + P*n1*n2/((n1 + n2 + n3)*(n1 + n2 + n3));
        break;
    default:
        break;
    }
}

static int Simple_Solution_get_param_number(void) {
    return 23;
}

static const char *paramNames[23] = {"T_r", "P_r", "Wh12", "Ws12", "Wv12", "dWh12", "dWs12", "dWv12", "Wh13", "Ws13", "Wv13", "dWh13", "dWs13", "dWv13", "Wh23", "Ws23", "Wv23", "dWh23", "dWs23", "dWv23", "Wh123", "Ws123", "Wv123"};
static const char *paramUnits[23] = {"K", "bar", "J/m", "J/K-m", "J/bar-m", "J/m", "J/K-m", "J/bar-m", "J/m", "J/K-m", "J/bar-m", "J/m", "J/K-m", "J/bar-m", "J/m", "J/K-m", "J/bar-m", "J/m", "J/K-m", "J/bar-m", "J/m", "J/K-m", "J/bar-m"};

static const char **Simple_Solution_get_param_names(void) {
    return paramNames;
}

static const char **Simple_Solution_get_param_units(void) {
    return paramUnits;
}

static void Simple_Solution_get_param_values(double **values) {
    (*values)[0] = T_r;
    (*values)[1] = P_r;
    (*values)[2] = Wh12;
    (*values)[3] = Ws12;
    (*values)[4] = Wv12;
    (*values)[5] = dWh12;
    (*values)[6] = dWs12;
    (*values)[7] = dWv12;
    (*values)[8] = Wh13;
    (*values)[9] = Ws13;
    (*values)[10] = Wv13;
    (*values)[11] = dWh13;
    (*values)[12] = dWs13;
    (*values)[13] = dWv13;
    (*values)[14] = Wh23;
    (*values)[15] = Ws23;
    (*values)[16] = Wv23;
    (*values)[17] = dWh23;
    (*values)[18] = dWs23;
    (*values)[19] = dWv23;
    (*values)[20] = Wh123;
    (*values)[21] = Ws123;
    (*values)[22] = Wv123;

}

static int Simple_Solution_set_param_values(double *values) {
    T_r = values[0];
    P_r = values[1];
    Wh12 = values[2];
    Ws12 = values[3];
    Wv12 = values[4];
    dWh12 = values[5];
    dWs12 = values[6];
    dWv12 = values[7];
    Wh13 = values[8];
    Ws13 = values[9];
    Wv13 = values[10];
    dWh13 = values[11];
    dWs13 = values[12];
    dWv13 = values[13];
    Wh23 = values[14];
    Ws23 = values[15];
    Wv23 = values[16];
    dWh23 = values[17];
    dWs23 = values[18];
    dWv23 = values[19];
    Wh123 = values[20];
    Ws123 = values[21];
    Wv123 = values[22];

    return 1;
}

static double Simple_Solution_get_param_value(int index) {
    double result = 0.0;
    switch (index) {
    case 0:
        result = T_r;
        break;
    case 1:
        result = P_r;
        break;
    case 2:
        result = Wh12;
        break;
    case 3:
        result = Ws12;
        break;
    case 4:
        result = Wv12;
        break;
    case 5:
        result = dWh12;
        break;
    case 6:
        result = dWs12;
        break;
    case 7:
        result = dWv12;
        break;
    case 8:
        result = Wh13;
        break;
    case 9:
        result = Ws13;
        break;
    case 10:
        result = Wv13;
        break;
    case 11:
        result = dWh13;
        break;
    case 12:
        result = dWs13;
        break;
    case 13:
        result = dWv13;
        break;
    case 14:
        result = Wh23;
        break;
    case 15:
        result = Ws23;
        break;
    case 16:
        result = Wv23;
        break;
    case 17:
        result = dWh23;
        break;
    case 18:
        result = dWs23;
        break;
    case 19:
        result = dWv23;
        break;
    case 20:
        result = Wh123;
        break;
    case 21:
        result = Ws123;
        break;
    case 22:
        result = Wv123;
        break;

    default:
        break;
    }
    return result;
}

static int Simple_Solution_set_param_value(int index, double value) {
    int result = 1;
    switch (index) {
    case 0:
        T_r = value;
        break;
    case 1:
        P_r = value;
        break;
    case 2:
        Wh12 = value;
        break;
    case 3:
        Ws12 = value;
        break;
    case 4:
        Wv12 = value;
        break;
    case 5:
        dWh12 = value;
        break;
    case 6:
        dWs12 = value;
        break;
    case 7:
        dWv12 = value;
        break;
    case 8:
        Wh13 = value;
        break;
    case 9:
        Ws13 = value;
        break;
    case 10:
        Wv13 = value;
        break;
    case 11:
        dWh13 = value;
        break;
    case 12:
        dWs13 = value;
        break;
    case 13:
        dWv13 = value;
        break;
    case 14:
        Wh23 = value;
        break;
    case 15:
        Ws23 = value;
        break;
    case 16:
        Wv23 = value;
        break;
    case 17:
        dWh23 = value;
        break;
    case 18:
        dWs23 = value;
        break;
    case 19:
        dWv23 = value;
        break;
    case 20:
        Wh123 = value;
        break;
    case 21:
        Ws123 = value;
        break;
    case 22:
        Wv123 = value;
        break;

    default:
        result = 0;
        break;
    }
    return result;
}

