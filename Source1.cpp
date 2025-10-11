#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

Point create_point();
void show_points(Point* list, int size);
void write_point_to_file(FILE* file, Point* points, int size);
void read_point_from_file(FILE* file);

enum Menu
{
    EXIT,
    CREATE_POINT,
    WRITE_POINT,
    READ_POINT
};

int main()
{
    Point* points = nullptr;
    FILE* file = nullptr;
    const char* path = "points.bin";
    int size = 0;
    int choice;

    do
    {
        cout << CREATE_POINT << "-create point \n"
            << WRITE_POINT << "-write point to file \n"
            << READ_POINT << "-read from file\n"
            << EXIT << "-exit\n";
        cin >> choice;

        switch (choice)
        {
        case CREATE_POINT:
        {
            if (points != nullptr)
            {
                delete[] points;
                points = nullptr;
            }
            cout << "Enter size: ";
            cin >> size;
            if (size <= 0) 
            { 
                cout << "Invalid size\n";
                size = 0;
                break;
            }
            points = new Point[size];
            for (int i = 0; i < size; i++)
            {
                points[i] = create_point();
            }
        }
        break;

        case WRITE_POINT:
        {
            if (points == nullptr || size == 0) 
            {
                cout << "No points to write\n";
                break;
            }

            errno_t code = fopen_s(&file, path, "ab");
            if (code == 0 && file != nullptr)
            {
                fwrite(points, sizeof(Point), size, file);
                fclose(file); 
                file = nullptr;
                cout << "Points written to file successfully!\n";
            }
            else
            {
                cout << "Error opening file for writing!\n";
            }
        }
        break;

        case READ_POINT:
        {
            errno_t code = fopen_s(&file, path, "rb");
            if (code == 0 && file != nullptr)
            {
                fseek(file, 0, SEEK_END);
                long total = ftell(file); 
                if (total <= 0) {
                    cout << "Error reading file\n";
                    fclose(file);
                    break;
                }

                int count = total / sizeof(Point);

                if (points != nullptr)
                {
                    delete[] points;
                    points = nullptr;
                }

                points = new Point[count];
                fseek(file, 0, SEEK_SET);
                size_t read_count = fread(points, sizeof(Point), count, file);
                fclose(file); 
                file = nullptr;

                if (read_count == count) 
                {
                    size = count; 
                    cout << "Points read from file:\n";
                    show_points(points, size); 
                }
                else 
                {
                    cout << "Error reading points from file\n";
                    delete[] points;
                    points = nullptr;
                    size = 0;
                }
            }
            else
            {
                cout << "Error opening file for reading\n";
            }
        }
        break;

        case EXIT:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice\n";
            break;
        }

    } while (choice != EXIT);

    if (points != nullptr)
        delete[] points;
    if (file != nullptr) 
    {
        fclose(file);
    }

    return 0;
}

Point create_point() 
{
    Point p;
    cout << "Enter x: ";
    cin >> p.x;
    cout << "Enter y: ";
    cin >> p.y;
    return p;
}

void show_points(Point* list, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Point " << i + 1 << ": x:" << list[i].x << " y:" << list[i].y << endl;
    }
}

void write_point_to_file(FILE* file, Point* points, int size)
{
    // 
}

void read_point_from_file(FILE* file)
{
    // 
}