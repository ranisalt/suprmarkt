namespace suprmarkt {
namespace client {

class MockPreference : public Preference {
 public:
  MOCK_METHOD1(chooseQueue,
      Checkout&(const deque<Checkout>));
};

}  // namespace client
}  // namespace suprmarkt
