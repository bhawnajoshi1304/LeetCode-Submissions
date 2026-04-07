class Robot {
public:
    int w, h, p, d;
    bool moved;

    Robot(int width, int height) {
        w = width;
        h = height;
        moved = false;
        p = 2 * (w - 1) + 2 * (h - 1);
        d = 0;
    }

    void step(int num) {
        moved = true;
        d = (d + num) % p;
    }

    vector<int> getPos() {
        int x = d;
        if (x < w)
            return {x, 0};
        if (x < w + h - 1)
            return {w - 1, x - (w - 1)};
        if (x < 2 * w + h - 2)
            return {w - 1 - (x - (w + h - 2)), h - 1};
        return {0, h - 1 - (x - (2 * w + h - 3))};
    }

    string getDir() {
        if (!moved)
            return "East";
        int x = d;
        if (x > 0 && x < w)
            return "East";
        if (x >= w && x < w + h - 1)
            return "North";
        if (x >= w + h - 1 && x < 2 * w + h - 2)
            return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */