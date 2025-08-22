// Simplified Ride-Sharing Dispatch Simulator
// Concept: Assign drivers to riders based on distance and ratings.
// Uses queue for riders and priority_queue for nearest driver.
// Build: g++ -std=c++17 -O2 ridesim.cpp -o ridesim

#include <bits/stdc++.h>
using namespace std;

struct Location {
    double x, y;
};

double distance(const Location &a, const Location &b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

struct Driver {
    int id;
    string name;
    Location loc;
    double rating;
    bool available;
};

struct Rider {
    int id;
    string name;
    Location pickup, dropoff;
};

struct Ride {
    int id;
    string riderName, driverName;
    double pickupDist, tripDist;
};

class Dispatcher {
    int nextDriverId = 1, nextRiderId = 1, nextRideId = 1;
    unordered_map<int, Driver> drivers;
    queue<Rider> riderQueue;
    vector<Ride> history;

public:
    int addDriver(string name, double x, double y, double rating) {
        Driver d{nextDriverId++, name, {x, y}, rating, true};
        drivers[d.id] = d;
        return d.id;
    }

    int addRider(string name, double px, double py, double dx, double dy) {
        Rider r{nextRiderId++, name, {px, py}, {dx, dy}};
        riderQueue.push(r);
        return r.id;
    }

    optional<Ride> dispatch() {
        if (riderQueue.empty()) return nullopt;

        Rider r = riderQueue.front();
        struct Candidate {
            int id; double dist; double rating;
        };
        struct Cmp {
            bool operator()(const Candidate&a, const Candidate&b) {
                if (a.dist != b.dist) return a.dist > b.dist;
                return a.rating < b.rating;
            }
        };

        priority_queue<Candidate, vector<Candidate>, Cmp> pq;
        for (auto &kv : drivers) {
            if (kv.second.available)
                pq.push({kv.first, distance(kv.second.loc, r.pickup), kv.second.rating});
        }
        if (pq.empty()) return nullopt;

        auto best = pq.top();
        Driver &d = drivers[best.id];
        d.available = false;

        Ride ride{nextRideId++, r.name, d.name, best.dist, distance(r.pickup, r.dropoff)};

        // Simulate completion instantly
        d.loc = r.dropoff;
        d.available = true;

        riderQueue.pop();
        history.push_back(ride);
        return ride;
    }

    void showDrivers() {
        cout << "\nDrivers:\n";
        for (auto &kv : drivers) {
            auto &d = kv.second;
            cout << "#" << d.id << " " << d.name << " loc(" << d.loc.x << "," << d.loc.y << ") "
                 << " rating:" << d.rating << " available:" << (d.available?"Yes":"No") << "\n";
        }
    }

    void showRiders() {
        cout << "\nRider Queue:\n";
        if (riderQueue.empty()) { cout << "(empty)\n"; return; }
        auto q = riderQueue;
        while(!q.empty()) {
            auto r = q.front(); q.pop();
            cout << "#" << r.id << " " << r.name << " pickup(" << r.pickup.x << "," << r.pickup.y << ") -> drop(" << r.dropoff.x << "," << r.dropoff.y << ")\n";
        }
    }

    void showHistory() {
        cout << "\nRide History:\n";
        if (history.empty()) { cout << "(none)\n"; return; }
        for (auto &h : history) {
            cout << "Ride#" << h.id << ": Rider " << h.riderName << " with Driver " << h.driverName
                 << " PickupDist:" << h.pickupDist << " TripDist:" << h.tripDist << "\n";
        }
    }
};

int main() {
    Dispatcher d;
    while (true) {
        cout << "\n1) Add Driver  2) Add Rider  3) Dispatch  4) Show Drivers  5) Show Riders  6) Show History  0) Exit\nChoice: ";
        int c; cin >> c;
        if (c==0) break;
        if (c==1) {
            string name; double x,y,r; cout << "Name x y rating: ";
            cin >> name >> x >> y >> r;
            cout << "Driver#"<< d.addDriver(name,x,y,r)<<" added\n";
        } else if (c==2) {
            string name; double px,py,dx,dy; cout << "Name px py dx dy: ";
            cin >> name >> px >> py >> dx >> dy;
            cout << "Rider#"<< d.addRider(name,px,py,dx,dy)<<" added\n";
        } else if (c==3) {
            auto ride=d.dispatch();
            if(!ride) cout << "No match\n";
            else cout << "Ride#"<<ride->id<<" assigned: "<<ride->riderName<<" -> "<<ride->driverName<<"\n";
        } else if (c==4) d.showDrivers();
        else if (c==5) d.showRiders();
        else if (c==6) d.showHistory();
    }
}
