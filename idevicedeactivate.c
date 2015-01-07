#include <stdio.h>
#include <libimobiledevice/lockdown.h>

int main(int argc, char **argv)
{
	idevice_t device = NULL;
	lockdownd_client_t client = NULL;
	lockdownd_error_t ldret = LOCKDOWN_E_UNKNOWN_ERROR;

	if (idevice_new(&device, NULL) != IDEVICE_E_SUCCESS) {
		fprintf(stderr, "No device found, is it plugged in?\n");
		return -1;
	}

	printf("Connecting to device\n");
	ldret = lockdownd_client_new_with_handshake(device, &client, "idevicedeactivate");
	if (ldret != LOCKDOWN_E_SUCCESS) {
		fprintf(stderr, "ERROR: Could not connect to lockdownd, error %d\n", ldret);
		idevice_free(device);
		return -1;
	}

	printf("Deactivating device\n");
	ldret = lockdownd_deactivate(client);
	if (ldret != LOCKDOWN_E_SUCCESS) {
		fprintf(stderr, "ERROR: Could not deactivate the device, error %d\n", ldret);
		lockdownd_client_free(client);
		idevice_free(device);
		return -1;
	}

	lockdownd_client_free(client);
	idevice_free(device);

	return 0;
}
