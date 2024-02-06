#include "opt_acpi.h"

#include <sys/cdefs.h>
#include <sys/param.h>
#include <sys/systm.h>
#include <sys/bus.h>
#include <sys/kernel.h>
/* #include <machine/cpufunc.h> */

#include <contrib/dev/acpica/include/acpi.h>
#include <contrib/dev/acpica/include/accommon.h>

#include "acpi_if.h"

#include <sys/module.h>

ACPI_MODULE_NAME("GPD")

static char* gpd_ids[] = {"INT33D5", NULL};

struct acpi_gpd_softc {
    device_t dev;
    ACPI_HANDLE handle;
};

static int acpi_gpd_probe(device_t dev) {
    if (acpi_disable("gpd") || device_get_unit(dev) != 0) {
        return ENXIO;
    }

    int rv = ACPI_ID_PROBE(device_get_parent(dev), dev, gpd_ids, NULL);
    if (rv <= 0) {
        device_set_desc(dev, "GPD Micro");
    }
    
    return rv;
}

static int acpi_gpd_attach(device_t dev) {
    return 0;
}

static int acpi_gpd_detach(device_t dev) {
    return 0;
}

static int acpi_gpd_resume(device_t dev) {
    return 0;
}

static device_method_t acpi_gpd_driver_methods[] = {
    DEVMETHOD(device_probe, acpi_gpd_probe),
    DEVMETHOD(device_attach, acpi_gpd_attach),
    DEVMETHOD(device_detach, acpi_gpd_detach),
    DEVMETHOD(device_resume, acpi_gpd_resume),
    
    DEVMETHOD_END
};

static driver_t acpi_gpd_driver = {
    "acpi_gpd",
    acpi_gpd_driver_methods,
    sizeof(struct acpi_gpd_softc)
};

DRIVER_MODULE(acpi_gpd, acpi, acpi_gpd_driver, 0, 0);
MODULE_DEPEND(acpi_gpd, acpi, 1, 1, 1);
