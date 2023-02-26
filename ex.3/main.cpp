#include <deque>
#include <iostream>
#include <list>
#include <random>
#include <utility>

typedef enum {
    LOW,
    NORMAL,
    HIGH
} ElementPriority;

typedef struct {
    std::string name;
} QueueElement;

class QueueWithPriority {
   private:
    std::deque<std::pair<QueueElement, ElementPriority>> _queue;

   public:
    QueueWithPriority();

    ~QueueWithPriority();

    void PutElementToQueue(const QueueElement &element, ElementPriority priority);

    QueueElement GetElementFromQueue();

    [[nodiscard]] bool isEmpty() const;
};

QueueWithPriority::QueueWithPriority() = default;

QueueWithPriority::~QueueWithPriority() {
    _queue.clear();
}

void QueueWithPriority::PutElementToQueue(const QueueElement &element, ElementPriority priority) {
    _queue.emplace_back(element, priority);
}

QueueElement QueueWithPriority::GetElementFromQueue() {
    if (_queue.empty()) {
        auto r = _queue.front().first;
        _queue.pop_back();

        return r;
    }

    auto r = _queue.front();
    auto t = _queue.begin();

    for (auto it = _queue.begin() + 1; it != _queue.end() && r.second != ElementPriority::HIGH; it++) {
        if ((*it).second > r.second) {
            r = *it;
            t = it;
        }
    }
    _queue.erase(t);

    return r.first;
}

bool QueueWithPriority::isEmpty() const {
    return _queue.empty();
}

int main() {
    QueueWithPriority queueWithPriority;

    queueWithPriority.PutElementToQueue(QueueElement{"1"}, ElementPriority::LOW);
    queueWithPriority.PutElementToQueue(QueueElement{"2"}, ElementPriority::NORMAL);
    queueWithPriority.PutElementToQueue(QueueElement{"3"}, ElementPriority::HIGH);
    queueWithPriority.PutElementToQueue(QueueElement{"4"}, ElementPriority::LOW);
    queueWithPriority.PutElementToQueue(QueueElement{"5"}, ElementPriority::HIGH);
    queueWithPriority.PutElementToQueue(QueueElement{"6"}, ElementPriority::HIGH);

    while (!queueWithPriority.isEmpty()) {
        auto element = queueWithPriority.GetElementFromQueue();
        std::cout << element.name << std::endl;
    }

    std::list<int> l(15);

    std::mt19937 rng(std::random_device{}());
    std::generate_n(l.begin(), 15, [&]() { return std::uniform_int_distribution<int>{1, 20}(rng); });

    for (auto item : l) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    auto i = l.begin();
    auto j = l.end();

    --j;
    while (i != j) {
        std::cout << *i << " " << *j << " ";
        ++i;
        --j;
    }
    --j;
    std::cout << *j;

    return 0;
}
