using System;
namespace GymFitnessManagement 
{
    //Abstract class Member
    abstract class Member{
        private int member_id; //Unique member id
        private string? member_name; //nullable to allow no name initially
        private int member_age; //Member age

        //Properties to access member id
        public int Member_id{
            get { return member_id; }
            set { member_id = value; }
        }
        //Properties to access member name + NULLABLE
        public string? Member_name{
            get { return member_name; }
            set { member_name = value; }
        }
        //Properties to access member age
        public int Member_age{
            get { return member_age; }
            set { member_age = value; }
        }
        //Constructor to initialize member details 
        public Member(int member_id, string member_name, int member_age){
            Member_id = member_id;
            Member_name = member_name;
            Member_age = member_age;
        }

        //Method to calculate discount based on age
        protected double GetDiscount(){
            double discount;
            if(Member_age <= 18 || Member_age >= 65){
                discount = 0.25;
            }
            else{
                discount = 0.0;
            }
            return discount;
        }
        //Abstract method that is implemented in derived classes
        public abstract void CalculateMonthlyFee();

        //Method displays member details
        public void DisplayDetails(){
            Console.WriteLine($"Member ID: {Member_id}");
            Console.WriteLine($"Member Name: {Member_name}");
            Console.WriteLine($"Member Age: {Member_age}");
        }
    }
    //RegularMember class inherits from Member
    class RegularMember : Member{
        private double WorkoutPlanFee;
        protected const double base_fee = 50.0;

        //Constructor to initialize RegularMember details
        public RegularMember(int member_id, string member_name, int member_age, double WorkoutPlanFee) : base(member_id, member_name, member_age){
            this.WorkoutPlanFee = WorkoutPlanFee;
          }
          
        //Method to calculate monthly fee for a regular member
        public override void CalculateMonthlyFee(){
            double discount = GetDiscount();
            double monthly_fee = base_fee + WorkoutPlanFee - ((base_fee + WorkoutPlanFee) * discount);
            Console.WriteLine($"{Member_name} monthly fee is: {monthly_fee}$");
          }
        }
    //PremiumMember class inherits from Member
    class PremiumMember : Member{
        private double PersonalTrainerFee;
        private double DietPlanFee;
        protected const double base_fee = 100.0;

        //Constructor to initialize PremiumMember details
        public PremiumMember(int member_id, string member_name, int member_age, double PersonalTrainerFee, double DietPlanFee) : base(member_id, member_name, member_age){
            this.PersonalTrainerFee = PersonalTrainerFee;
            this.DietPlanFee = DietPlanFee;
          }

        //Method to calculate monthly fee for a premium member
        public override void CalculateMonthlyFee()
        {
            double discount = GetDiscount();
            double monthly_fee = base_fee + PersonalTrainerFee + DietPlanFee - ((base_fee + PersonalTrainerFee + DietPlanFee) * discount);
            Console.WriteLine($"{Member_name} monthly fee is: {monthly_fee}$");
        }
    }

    // An interface to add gym management features without changing the class structure
    interface IGymManagement{
        void AddMember(Member member);
        void DisplayAllMembers();
    }

    //Gym class that implements the interface
    class Gym : IGymManagement{

        // A dynamic list that automatically adjusts as members are added or removed
        private List<Member> GymMembers = new List<Member>();
        
        //Method to add a member to the gym
        public void AddMember(Member member){
            GymMembers.Add(member);
            Console.WriteLine($"Member {member.Member_name} has been added successfully!");
        }
        //Method to display all members details in the gym
        public void DisplayAllMembers(){

            if(GymMembers.Count == 0){
                Console.WriteLine("No members in the gym");
                return;
            }
            Console.WriteLine("----------------Gym Members Info--------------- ");
            foreach(Member member in GymMembers){
                member.DisplayDetails();
                member.CalculateMonthlyFee();
                Console.WriteLine();
            }
            Console.WriteLine("------------------------------------------------");
        }

        }

    class Program
    {
        static void Main(string[] args)
        {
            //Creating an object of the Gym class
            Gym gym = new Gym();

            //Creating objects of RegularMember and PremiumMember classes
            RegularMember member1 = new RegularMember(1, "Mariam", 25, 20.0);
            PremiumMember member2 = new PremiumMember(2, "Hazem", 36, 30.0, 40.0);
            PremiumMember member3 = new PremiumMember(3, "Farouk", 70, 30.0, 40.0);
            RegularMember member4 = new RegularMember(4, "Soha", 15, 20.0);

            Console.WriteLine();
            //Adding members to the gym
            gym.AddMember(member1);
            gym.AddMember(member2);
            gym.AddMember(member3);
            gym.AddMember(member4);

            Console.WriteLine();
            //Displaying all members in the gym
            gym.DisplayAllMembers();

            } 
        } 
    }