
class Main{
    public static void main(String []args)
    {
        DriveStrategy drive1 = new NormalDriveStretegy();
        DriveStrategy drive2 = new FastDriveStretegy();
        Vehicle obj = new NormalVehicle();
        Vehicle obj1 = new FastVehicle();
        obj1.drive();
    }
}

class Vehicle{
    public DriveStrategy obj;
    Vehicle(DriveStrategy obj)
    {
        this.obj = obj;
    }
    public void drive(){
        obj.drive();
    }
}

interface DriveStrategy{
    void drive();
}

class NormalDriveStretegy implements DriveStrategy{
    
    public void drive(){
        System.out.println("NOrmal drive");
    }
};

class FastDriveStretegy implements DriveStrategy{
    public void drive(){
        System.out.println("fast drive");
    }
}

class NormalVehicle extends Vehicle{
    NormalVehicle(){
        super(new NormalDriveStretegy());
    }
}

class FastVehicle extends Vehicle{
    FastVehicle(){
        super(new FastDriveStretegy());
    }
}




