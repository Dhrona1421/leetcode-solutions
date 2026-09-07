class ParkingSystem {
public:
    int slots[4];

    ParkingSystem(int big, int medium, int small) {
        slots[1] = big;
        slots[2] = medium;
        slots[3] = small;
    }

    bool addCar(int carType) {
        if (slots[carType] == 0)
            return false;

        slots[carType]--;
        return true;
    }
};