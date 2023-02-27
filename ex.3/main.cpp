// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

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
/*
 * @brief - Constructor, creates an empty queue.
 */
QueueWithPriority::QueueWithPriority() = default;
/*
 * @brief - Destructor
 */
QueueWithPriority::~QueueWithPriority() {
    _queue.clear();
}
/*
 * @brief - A function that adds an element to the queue with a given priority.
 */
QueueElement QueueWithPriority::GetElementFromQueue() {
    if (_queue.empty()) {
        auto r = _queue.front().first;
        _queue.pop_back();

        return r;
    }
    // Returns a reference to the __firt__ element in the queue.
    auto r = _queue.front();
    // Returns a reference to the __last__ element in the queue.
    auto t = _queue.begin();

    for (auto it = _queue.begin() + 1; it != _queue.end() && r.second != ElementPriority::HIGH; it++) {
        if ((*it).second > r.second) {
            r = *it;
            t = it;
        }
    }
    // Removes elements from a range whose start and end point to iterators.
    _queue.erase(t);

    return r.first;
}
/*
 * @brief - Setting our alimony in place.
 */
void QueueWithPriority::PutElementToQueue(const QueueElement &element, ElementPriority priority) {
    _queue.emplace_back(element, priority);
}
/*
 * @brief - Checking for an existing element.
 */
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
    // Generate random 15 array values ranging from 1...20.
    std::mt19937 rng(std::random_device{}());
    std::generate_n(l.begin(), 15, [&]() {
        return std::uniform_int_distribution<int>{1, 20}(rng);
    });
    // Output the resulting array.
    for (auto item : l) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    // Get a reference to the __first__ and __end__ of the array.
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
