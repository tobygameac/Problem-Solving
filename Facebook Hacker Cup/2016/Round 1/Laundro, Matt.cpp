#include <algorithm>
#include <iostream>
#include <queue>

struct WashMachine {
  long long available_time;
  long long washing_gap;

  bool operator <(const WashMachine &other) const {
    return (available_time + washing_gap) > (other.available_time + other.washing_gap);
  }
};

struct DryMachine {
  long long available_time;
  long long drying_gap;

  bool operator <(const DryMachine &other) const {
    return (available_time + drying_gap) > (other.available_time + other.drying_gap);
  }
};

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    long long L, N, M, D;
    std::cin >> L >> N >> M >> D;

    std::priority_queue<WashMachine> wash_machines;
    for (long long i = 0; i < N; ++i) {
      WashMachine wash_machine;
      wash_machine.available_time = 0;
      std::cin >> wash_machine.washing_gap;
      wash_machines.push(wash_machine);
    }

    DryMachine dry_machine;
    dry_machine.available_time = 0;
    dry_machine.drying_gap = D;
    std::priority_queue<DryMachine> dry_machines;
    for (long long i = 0; i < L && i < M; ++i) {
      dry_machines.push(dry_machine);
    }

    long long max_end_time = 0;

    for (long long i = 0; i < L; ++i) {
      WashMachine old_wash_machine = wash_machines.top();
      wash_machines.pop();

      DryMachine old_dry_machine = dry_machines.top();
      dry_machines.pop();

      long long wash_end_time = old_wash_machine.available_time + old_wash_machine.washing_gap;
      WashMachine new_wash_machine;
      new_wash_machine.available_time = wash_end_time;
      new_wash_machine.washing_gap = old_wash_machine.washing_gap;

      long long dry_end_time = std::max(wash_end_time, old_dry_machine.available_time) + old_dry_machine.drying_gap;

      DryMachine new_dry_machine;
      new_dry_machine.available_time = dry_end_time;
      new_dry_machine.drying_gap = old_dry_machine.drying_gap;

      max_end_time = std::max(max_end_time, dry_end_time);

      wash_machines.push(new_wash_machine);

      dry_machines.push(new_dry_machine);
    }
    
    std::cout << "Case #" << t << ": " << max_end_time << "\n";
  }
  return 0;
}
