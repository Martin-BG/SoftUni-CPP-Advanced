#ifndef __DEFINES_H__
#define __DEFINES_H__

enum class Commands {
  INIT,     // Init Q
  IN,       // GasIn Q T
  OUT,      // GasOut Q T
  DEMAND,   // DEMAND Q T
  END       // End
};

Commands str2command(const std::string & str);

class GasReservoir {

    private:
        static std::unique_ptr< GasReservoir > theReservoir;

        int cycles;
        int amount;

        GasReservoir() : cycles(0), amount(0) {}
        GasReservoir(const GasReservoir &) = delete;
        GasReservoir & operator=(const GasReservoir &) = delete;

    public:

        static GasReservoir & get(void);

        int getCycles(void) const { return cycles; }
        void addCycles(int additionalCycles_) { cycles += additionalCycles_; } 

        int getQuantity(void) const { return amount; }
        void setQuantity(int newAmount) { amount = newAmount; }
};

#endif