"""
Aria Art Plotter - XIAO OLED COMMUNICATION

Copyright (c) 2025 Gustavo Mayoral

This file is part of the Aria Art Plotter project.

Hardware License: CERN-OHL-S-2.0
Documentation License: CC BY-SA 4.0
Software License: GPL-3.0

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.

Project: https://github.com/gustavomayoral/aria_art_plot
Support: https://ko-fi.com/ariaartplot
Web: https://aria-art.com

"""

#!/usr/bin/env python3
# Save as ~/klipper/klippy/extras/oled_display.py

import serial
import time
import logging
import threading

class OLEDDisplay:
    def __init__(self, config):
        self.printer = config.get_printer()
        self.name = config.get_name()
        
        # Configuration
        self.serial_port = config.get('serial_port')
        self.baud_rate = config.getint('baud_rate', 115200)
        self.timeout = config.getfloat('timeout', 1.0)
        
        # Serial connection
        self.serial_conn = None
        self.is_connected = False
        self.connection_lock = threading.Lock()
        
        # Register event handlers
        self.printer.register_event_handler("klippy:ready", self._handle_ready)
        self.printer.register_event_handler("klippy:disconnect", self._handle_disconnect)
        
        # Register G-code commands
        gcode = self.printer.lookup_object('gcode')
        gcode.register_command('OLED_MESSAGE', self.cmd_OLED_MESSAGE,
                             desc=self.cmd_OLED_MESSAGE_help)
        gcode.register_command('OLED_CLEAR', self.cmd_OLED_CLEAR,
                             desc=self.cmd_OLED_CLEAR_help)
        gcode.register_command('OLED_STATUS', self.cmd_OLED_STATUS,
                             desc=self.cmd_OLED_STATUS_help)
    
    def _handle_ready(self):
        """Initialize when Klipper is ready"""
        # Add a small delay to ensure Arduino is fully initialized
        time.sleep(1)
        self._connect()
        if self.is_connected:
            # Send a clear command first, then the ready message
            self._send_command("CLEAR")
            time.sleep(0.2)
            self._send_command("MSG:ARIA Loaded!")
    
    def _handle_disconnect(self):
        """Clean up on disconnect"""
        self._disconnect()
    
    def _connect(self):
        """Connect to the OLED Arduino"""
        with self.connection_lock:
            try:
                self.serial_conn = serial.Serial(
                    self.serial_port, 
                    self.baud_rate, 
                    timeout=self.timeout
                )
                time.sleep(2)  # Wait for Arduino initialization
                
                # Test connection
                response = self._send_command_sync("STATUS")
                if response and "READY" in response:
                    self.is_connected = True
                    logging.info("OLED Display: Connected successfully")
                else:
                    self.is_connected = True  # Assume connected even without response
                    logging.info("OLED Display: Connected (no status response)")
                    
            except Exception as e:
                logging.error(f"OLED Display: Connection failed - {e}")
                self.is_connected = False
                if self.serial_conn:
                    try:
                        self.serial_conn.close()
                    except:
                        pass
                    self.serial_conn = None
    
    def _disconnect(self):
        """Disconnect from OLED"""
        with self.connection_lock:
            self.is_connected = False
            if self.serial_conn:
                try:
                    self.serial_conn.close()
                except:
                    pass
                self.serial_conn = None
    
    def _send_command(self, command):
        """Send command to OLED (non-blocking)"""
        if not self.is_connected or not self.serial_conn:
            return False
        
        try:
            with self.connection_lock:
                self.serial_conn.write(f"{command}\n".encode())
                self.serial_conn.flush()
            return True
        except Exception as e:
            logging.error(f"OLED Display: Send failed - {e}")
            return False
    
    def _send_command_sync(self, command):
        """Send command and wait for response"""
        if not self.is_connected or not self.serial_conn:
            return None
        
        try:
            with self.connection_lock:
                self.serial_conn.write(f"{command}\n".encode())
                self.serial_conn.flush()
                response = self.serial_conn.readline().decode().strip()
                return response
        except Exception as e:
            logging.error(f"OLED Display: Sync send failed - {e}")
            return None
    
    def send_message(self, message):
        """Public method to send message (always clears first)"""
        # Always clear before sending new message to prevent overlap
        self._send_command("CLEAR")
        time.sleep(0.1)  # Small delay to ensure clear completes
        return self._send_command(f"MSG:{message}")
    
    def clear_display(self):
        """Public method to clear display"""
        return self._send_command("CLEAR")
    
    # G-code command handlers
    cmd_OLED_MESSAGE_help = "Send message to OLED display"
    def cmd_OLED_MESSAGE(self, gcmd):
        message = gcmd.get('MSG', 'Hello World')
        success = self.send_message(message)
        if success:
            gcmd.respond_info(f"OLED: {message}")
        else:
            gcmd.respond_error("OLED: Failed to send message")
    
    cmd_OLED_CLEAR_help = "Clear OLED display"
    def cmd_OLED_CLEAR(self, gcmd):
        success = self.clear_display()
        if success:
            gcmd.respond_info("OLED: Display cleared")
        else:
            gcmd.respond_error("OLED: Failed to clear display")
    
    cmd_OLED_STATUS_help = "Check OLED connection status"
    def cmd_OLED_STATUS(self, gcmd):
        if self.is_connected:
            gcmd.respond_info("OLED: Connected")
        else:
            gcmd.respond_info("OLED: Disconnected")

def load_config(config):
    return OLEDDisplay(config)
