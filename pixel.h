#ifndef PIXEL_H
#define PIXEL_H

class pixel
{
    private:
        int r, g, b;

    public:
        pixel(int r = 0, int g = 0, int b = 0);

        int getR() const;
        int getG() const;
        int getB() const;

        void set(int r, int g, int b);
        void add(const pixel& other);
        void divide(int value);
};

#endif