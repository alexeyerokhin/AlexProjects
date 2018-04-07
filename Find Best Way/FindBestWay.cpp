#include <iostream>
#include <string>

int find_best_way(const int i, const int j, int** arr, const int N, const int M, std::string& best_way)
{
    if (i < N - 1 && j < M - 1)
    {
        std::string way_right;
        auto right = find_best_way(i, j + 1, arr, N, M, way_right);

        std::string way_down;
        auto down = find_best_way(i + 1, j, arr, N, M, way_down);

        if (right > down) {
            best_way = "R" + way_right;
            return arr[i][j] + right;
        } else {
            best_way = "D" + way_down;
            return arr[i][j] + down;
        }
    }
    else if (i < N - 1 && j == M-1)
    {
        int sum = 0;
        best_way = std::string("");
        for (int k = i; k < N - 1; ++k) {
            sum += arr[k][M - 1];
            best_way += "D";
        }
        sum += arr[N - 1][M - 1];

        return sum;
    }
    else // (i == N - 1 && j <= M - 1)
    {
        int sum = 0;
        best_way = std::string("");
        for (int k = j; k < M - 1; ++k) {
            sum += arr[N - 1][k];
            best_way += "R";
        }
        sum += arr[N - 1][M - 1];

        return sum;
    }
}

int main()
{
    int N; // lines
    int M; // columns

    std::cin >> N >> M;

    // Filling array
    int** arr = new int*[N];

    for (int i = 0; i < N; ++i) {
        arr[i] = new int[M];
    }

    for (int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            std::cin >> arr[i][j];
        }
    }

    std::string best_way = "";
    auto way_value = find_best_way(0, 0, arr, N, M, best_way);

    std::cout << "Best way:\n" << best_way << "\nWay value:\n" << way_value << std::endl;

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}