#include <gtest/gtest.h>
#include "behaviour_tree/behaviour_tree.h"

using namespace behaviour_tree;

// Helpers ---------------------------------------------------------------------------------------
Status simple_action (const bool check_conditions, const bool action_executed){
  Status status;

  if (check_conditions) {
    if (action_executed) {
      status = Status::kSuccess;
    }else {
      status = Status::kRunning;
    }
  }else {
    status = Status::kFailure;
  }

  std::cout << "Status : " << check_conditions << " : " << action_executed << " : " << status_to_str(status) << std::endl;
  return status;
};

auto AlwaysSuccess = [](){return Status::kSuccess;};
auto AlwaysRunning = [](){return Status::kRunning;};
auto AlwaysFailed = [](){return Status::kFailure;};

TEST(BehaviourTree, leaf_basics) {

  Leaf leaf_q(AlwaysSuccess);
  EXPECT_EQ(leaf_q.Tick(), Status::kSuccess);

  Leaf leaf_b(AlwaysRunning);
  EXPECT_EQ(leaf_b.Tick(), Status::kRunning);

  Leaf leaf_c(AlwaysFailed);
  EXPECT_EQ(leaf_c.Tick(), Status::kFailure);

}

TEST(BehaviourTree, no_loop_empty) {
  NoLoop no_loop;

  no_loop.Tick();
  EXPECT_EQ(no_loop.Tick(), Status::kFailure);

}

TEST(BehaviourTree, no_loop_one_child) {

  bool check_conditions = false;
  bool action_executed = false;
  NoLoop no_loop;

  no_loop.Add(std::make_unique<Leaf>([&]{return simple_action(check_conditions, action_executed);}));

  EXPECT_EQ(no_loop.Tick(), Status::kFailure);

  check_conditions = true;
  EXPECT_EQ(no_loop.Tick(), Status::kRunning);

  action_executed = true;
  EXPECT_EQ(no_loop.Tick(), Status::kSuccess);
  EXPECT_EQ(no_loop.Tick(), Status::kSuccess);

}

TEST(BehaviourTree, no_loop_multiple_children) {
  bool check_conditions = false;
  bool action_executed = false;
  NoLoop no_loop1;
  NoLoop no_loop2;

  no_loop1.Add(std::make_unique<Leaf>([&]{return simple_action(check_conditions, action_executed);}));
  no_loop2.Add(std::make_unique<Leaf>([&]{return simple_action(check_conditions, action_executed);}));

  EXPECT_EQ(no_loop1.Tick(), Status::kFailure);
  EXPECT_EQ(no_loop2.Tick(), Status::kFailure);

  check_conditions = true;
  EXPECT_EQ(no_loop1.Tick(), Status::kRunning);
  EXPECT_EQ(no_loop2.Tick(), Status::kRunning);

  action_executed = true;
  EXPECT_EQ(no_loop1.Tick(), Status::kSuccess);
  EXPECT_EQ(no_loop1.Tick(), Status::kSuccess);
  EXPECT_EQ(no_loop2.Tick(), Status::kSuccess);
  EXPECT_EQ(no_loop2.Tick(), Status::kSuccess);


}

TEST(BehaviourTree, selector_one_child) {
  bool check_conditions = false;
  bool action_executed = false;
  Selector selector;

  selector.Add(std::make_unique<Leaf>([&]{return simple_action(check_conditions, action_executed);}));
  EXPECT_EQ(selector.Tick(),Status::kFailure);
  selector.Reset();
  check_conditions = true;
  EXPECT_EQ(selector.Tick(), Status::kRunning);

  action_executed = true;
  EXPECT_EQ(selector.Tick(), Status::kSuccess);
  EXPECT_EQ(selector.Tick(), Status::kSuccess);

}

TEST(BehaviourTree, selector_multiple_children) {
  bool check_conditions = false;
  bool action_executed = false;
  Selector selector1;
  Selector selector2;

  selector1.Add(std::make_unique<Leaf>([&]{return simple_action(check_conditions, action_executed);}));
  EXPECT_EQ(selector1.Tick(),Status::kFailure);
  selector2.Add(std::make_unique<Leaf>([&]{return simple_action(check_conditions, action_executed);}));
  EXPECT_EQ(selector2.Tick(),Status::kFailure);
  selector1.Reset();
  selector2.Reset();
  check_conditions = true;
  EXPECT_EQ(selector1.Tick(), Status::kRunning);
  EXPECT_EQ(selector2.Tick(), Status::kRunning);

  action_executed = true;
  EXPECT_EQ(selector1.Tick(), Status::kSuccess);
  EXPECT_EQ(selector1.Tick(), Status::kSuccess);
  EXPECT_EQ(selector2.Tick(), Status::kSuccess);
  EXPECT_EQ(selector2.Tick(), Status::kSuccess);
}
