#ifndef PPM_IMAGE_H
#define PPM_IMAGE_H

class PPMImage
{
    public:
    
        PPMImage(int h, int w);
        
        const void PrintImage();
        
        void AddPoint(int X, int Y);
        void AddLine(int X1, int Y1, int X2, int Y2);
        void AddHorizLine(int X1, int Y1, int X2, int Y2);
        void AddVertLine(int X1, int Y1, int X2, int Y2);
        void AddDiagonalLine(int X1, int Y1, int X2, int Y2);

        // solves for Y, given X, on the line through two points
        // useful for adding diagonal lines to the image
        const float YGivenX(int X1, int Y1, int X2, int Y2, int X);
        
    private:
    
        const std::string MagicNumber {"P3"};
        const int MaxColor {255};
        int ImageHeight{0}; // in pixels
        int ImageWidth {0}; // in pixels

        std::vector<int> LineColour = {50, 50, 255};
        std::vector<int> BackgroundColour = {0, 0, 20};

        // internal image representation
        std::vector<std::vector<std::vector<int>>> Image2DArray;
};

#endif // PPM_IMAGE_H