ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>

// A single reservable resource (e.g. a room, projector, laptop cart).
struct Resource {
    int id;
    std::string name;
    int totalUnits;
    int availableUnits;
};

// Handles loading, storing, and reporting on all resources.
class ResourceManager {
private:
    std::vector<Resource> resources;

public:
  bool loadFromFile(const std::string& filename);
    void displayAll() const;
    void displayAvailability() const;

    Resource* findResource(int id);
    bool resourceExists(int id) const;

    bool decreaseAvailability(int id);
    bool increaseAvailability(int id);
};

#endif
 

