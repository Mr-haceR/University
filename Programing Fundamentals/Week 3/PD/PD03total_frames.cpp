#include <iostream>
using namespace std;
main() {
    int minutes, fps, total_frames;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    cout << "Enter frames per second (FPS): ";
    cin >> fps;
    total_frames = minutes * 60 * fps;
    cout << "Total number of frames: " << total_frames;
    
}