#include <sys/cdefs.h>

#include "opt_acpi.h"

#include <sys/bus.h>
#include <sys/kernel.h>
#include <sys/module.h>

#include "acpi_if.h"
#include "contrib/dev/acpica/include/acoutput.h"

ACPI_MODULE_NAME("GPD")

static driver_t acpi_gpd_driver = {
    DEVMETHOD(device_probe, acpi_gpd_probe),
    DEVMETHOD(device_attach, acpi_gpd_attach),
    DEVMETHOD(device_detach, acpi_gpd_detach),
    DEVMETHOD(device_resume, acpi_gpd_resume),

    DEVMETHOD_END
};

DRIVER_MODULE(acpi_gpd, acpi, acpi_gpd_driver, 0, 0);
MODULE_DEPEND(acpi_gpd, acpi, 1, 1, 1, 1);
