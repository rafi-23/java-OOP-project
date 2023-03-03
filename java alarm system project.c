import java.time.LocalTime;
import java.util.ArrayList;

public class AlarmSystem {
    private ArrayList<Alarm> alarms;
    
    public AlarmSystem() {
        alarms = new ArrayList<Alarm>();
    }
    
    public void addAlarm(Alarm alarm) {
        alarms.add(alarm);
    }
    
    public void removeAlarm(Alarm alarm) {
        alarms.remove(alarm);
    }
    
    public void checkAlarms() {
        LocalTime currentTime = LocalTime.now();
        
        for (Alarm alarm : alarms) {
            if (alarm.getTime().equals(currentTime)) {
                alarm.ring();
            }
        }
    }
}

public class Alarm {
    private String name;
    private LocalTime time;
    
    public Alarm(String name, LocalTime time) {
        this.name = name;
        this.time = time;
    }
    
    public String getName() {
        return name;
    }
    
    public LocalTime getTime() {
        return time;
    }
    
    public void ring() {
        System.out.println("Alarm " + name + " is ringing!");
    }
}

public class Main {
    public static void main(String[] args) {
        AlarmSystem alarmSystem = new AlarmSystem();
        
        Alarm wakeUpAlarm = new Alarm("Wake Up", LocalTime.of(7, 0));
        alarmSystem.addAlarm(wakeUpAlarm);
        
        Alarm breakfastAlarm = new Alarm("Breakfast", LocalTime.of(8, 0));
        alarmSystem.addAlarm(breakfastAlarm);
        
        Alarm lunchAlarm = new Alarm("Lunch", LocalTime.of(12, 0));
        alarmSystem.addAlarm(lunchAlarm);
        
        while (true) {
            alarmSystem.checkAlarms();
            
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
