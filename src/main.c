/*
 * Copyright (c) 2026 rfw
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <app_event_manager.h>
#include <caf/events/button_event.h>
#include <caf/key_id.h>

#define MODULE main
#include <caf/events/module_state_event.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(MODULE);

static bool event_handler(const struct app_event_header *eh)
{
	if (is_button_event(eh)) {
		const struct button_event *event = cast_button_event(eh);

		if (event->pressed) {
			printk("[%d,%d]\n", KEY_ROW(event->key_id), KEY_COL(event->key_id));
		}
		return false;
	}
	return false;
}

APP_EVENT_LISTENER(main, event_handler);
APP_EVENT_SUBSCRIBE(main, button_event);

int main(void)
{
	if (app_event_manager_init()) {
		LOG_ERR("Application Event Manager init failed");
		return -1;
	}

	module_set_state(MODULE_STATE_READY);
	return 0;
}
