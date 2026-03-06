#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct dragon_curve {
    int x;
    int y;
    int dir;
    int gen;
};

vector<vector<bool>> dragon_map(101, vector<bool>(101, false));
set<pair<int, int>> total_points;
set<pair<int, int>> points;
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, -1, 0, 1};

vector<pair<int, int>> rotate(int start_x, int start_y) {
    vector<pair<int, int>> new_points;

    for(auto point: points) {
        new_points.push_back(make_pair(start_x - (point.second - start_y), start_y + (point.first - start_x)));
    }

    return new_points;
}

void draw_map(dragon_curve info) {

    int last_point_x = info.x;
    int last_point_y = info.y;

    // 초기화 0세대 point 추가
    points.insert(make_pair(last_point_x, last_point_y));

    last_point_x += dir_x[info.dir];
    last_point_y += dir_y[info.dir];
    points.insert(make_pair(last_point_x, last_point_y));

    for(int i = 0; i < info.gen; i++) {
        // start point 기준으로 회전
        vector<pair<int, int>> new_points = rotate(info.x, info.y);

        // last_point_x, last_point_y가 offset으로 잡힘
        // offset만큼 이동한 points들 추가
        int last_new_point_x = info.x - (last_point_y - info.y);
        int last_new_point_y = info.y + (last_point_x - info.x);

        int x_offset = last_point_x - last_new_point_x;
        int y_offset = last_point_y - last_new_point_y;

        for(int j = 0; j < new_points.size(); j++) {
            points.insert(make_pair(new_points[j].first + x_offset, new_points[j].second + y_offset));
        }

        last_point_x = info.x + x_offset;
        last_point_y = info.y + y_offset;
    }

    // 전체 point에 대해서 범위 내 dragon_map 표시
    for(auto point: points) {
        if(point.first >= 0 && point.first <= 100 && point.second >= 0 && point.second <= 100) {
            dragon_map[point.second][point.first] = true;
        }
    }

    return;
}

int main() {

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        dragon_curve new_dragon;

        cin >> new_dragon.x >> new_dragon.y >> new_dragon.dir >> new_dragon.gen;

        draw_map(new_dragon);

        total_points.insert(points.begin(), points.end());
        points.clear();
    }

    // dragon_map 순회하면서 사각형 개수 세기
    int cnt = 0;

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(dragon_map[i][j] && dragon_map[i + 1][j] && dragon_map[i][j + 1] && dragon_map[i + 1][j + 1]) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}