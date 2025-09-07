// Scott Meyers

class Singleton{
	public:
		static Singleton& get_instance()
		{
			static Singleton instance;

			return instance;
		}
	void foo();

	private:
		Singleton();
};

int main()
{
	Singleton::get_instance()->foo();
	
}
