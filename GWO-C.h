
typedef struct {
    double fitness;
    double pos[13];
} Wolf;

void GWO(int lb, int ub, double (*fObj)(int j2, double pos2[]));

void showPack(void);
